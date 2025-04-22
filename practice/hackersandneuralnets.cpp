#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string>(n));

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) cin >> b[i][j];
    }
	
	vector<bool> seen(n);
	int best = 0;
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (b[i][j] == a[j]) {
				seen[j] = true;
				cnt++;
			}
		}
		best = max(best, cnt);
	}

	for (int i = 0; i < n; i++) if (!seen[i]) {
		cout << "-1\n";
		return;
	}

	cout << n + (n - best) * 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    