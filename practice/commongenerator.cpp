#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 4e5 + 10;
int mind[MAX_N];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	bool works = true;
	for (int i = 1; i < n; i++) {
		if (mind[a[i]] == a[i]) {
			works = false;
			break;
		}
	}
	if (!works) {
		cout << "-1\n";
		return;
	}

	if (a[0] == mind[a[0]]) { 
		for (int i = 1; i < n; i++) {
			int mn;
			if (a[i] % 2 == 0) mn = 2 * a[0];
			else mn = 2 * a[0] + mind[a[i]];
			if (a[i] < mn) {
				works = false;
				break;
			}
		}
		if (works) cout << a[0] << "\n";
		else cout << "-1\n";
	}
	else cout << "2\n";

	// p, 2p, 2p + 2 = 2(p + 1), 
	// p, 2p, 3p, 3(p + 1) 

	// 3, 6 
	// 7, 16
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < MAX_N; i++) mind[i] = i;
    for (int i = 2; i < MAX_N; i++) {
    	if (mind[i] != i) continue;
    	for (int j = i + i; j < MAX_N; j += i) mind[j] = min(mind[j], i);
    }

    int t;
    cin >> t;
    while (t--) solve();
}
    