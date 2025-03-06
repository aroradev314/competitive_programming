#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 3e5 + 10;
int a[MAX_N], par[MAX_N], has[MAX_N];
bool seen[MAX_N], seen_num[MAX_N];

int sieve[MAX_N];
set<int> divs[MAX_N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		has[a[i]] = i;
	}
	int s, t;
	cin >> s >> t;
	has[a[s]] = s;
	has[a[t]] = t;

	if (s == t) {
		cout << "1\n" << s;
		return;
	}
	if (a[s] == a[t] && a[s] != 1) {
		cout << "2\n";
		cout << s << " " << t << "\n";
		return;
	}

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int u = a[cur];
		for (int i : divs[u]) {
			if (seen_num[i]) continue;
			for (int j = i; j < MAX_N; j += i) {
				if (has[j] && !seen[has[j]]) {
					seen[has[j]] = true;
					q.push(has[j]);
					par[has[j]] = cur;
				}
				seen_num[j] = true;
			}
		}
	}

	if (par[t] == 0) cout << "-1\n";
	else {
		vector<int> path;
		while (t != s) {
			path.push_back(t);
			t = par[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		cout << sz(path) << "\n";
		for (int i : path) cout << i << " ";
		cout << "\n";
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < MAX_N; i++) {
    	if (sieve[i] == 0) {
    		for (int j = i + i; j < MAX_N; j += i) sieve[j] = i;
    	}
    }

    for (int i = 2; i < MAX_N; i++) {
    	if (sieve[i] == 0) divs[i].insert(i);
    	else {
    		divs[i].insert(sieve[i]);
    		for (int j : divs[i / sieve[i]]) {
    			divs[i].insert(j);
    			divs[i].insert(j * sieve[i]);
    		}
    	}
    }

    int t = 1;
    while (t--) solve();
}
    