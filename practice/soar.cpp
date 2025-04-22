#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++) cin >> b[i], b[i]--;

    vector<int> pair(n, -1);
	int same = -1;
	for (int i = 0; i < n; i++) {
		if ((pair[a[i]] != -1 && pair[a[i]] != b[i]) || (pair[b[i]] != -1 && pair[b[i]] != a[i])) {
			cout << "-1\n";
			return;
		}
		if (a[i] == b[i]) {
			if (same != -1 || n % 2 == 0) {
				cout << "-1\n";
				return;
			}
			same = a[i];
		}

		pair[a[i]] = b[i];
		pair[b[i]] = a[i];
		if (a[i] > b[i]) swap(a[i], b[i]);
	}

	vector<vector<int>> pos(n);
	vector<pair<int, int>> ops;
	for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
	
	for (int i = n - 1; i >= n / 2 + n % 2; i--) {
		if (sz(pos[a[i]]) == 1) {
			ops.push_back(n / 2, i);

		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    