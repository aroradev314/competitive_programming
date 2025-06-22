#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
	ll n, m;
	cin >> n >> m;

	if (m < n) cout << "-1\n";
	else if (m < 2 * n - 1) {
		int root = m - n + 1;
		cout << root << "\n";

		for (int i = 2; i <= n; i++) cout << 1 << " " << i << "\n";
	}
	else if (m <= (n * (n + 1)) / 2) {
		cout << n << "\n";

		if (n != 1) cout << n << " " << 1 << "\n";
		// cout << m << " " << n << " " << endl;
		m -= (1 + n);
		// cout << m << endl;
		for (int i = 2; i < n; i++) {
			ll left = m - (n - i - 1);

			if (left < i) {
				cout << left << " " << i << "\n";
				m -= left;
			}
			else {
				cout << n << " " << i << "\n";
				m -= i;
			}
		}

		assert(m == 0);
	}
	else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    