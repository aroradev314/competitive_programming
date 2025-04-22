#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2020;
ll m[MAX_N][MAX_N];
ll p[MAX_N][MAX_N];
ll px[MAX_N][MAX_N];
ll py[MAX_N][MAX_N];

ll rect(ll pref[][MAX_N], int x1, int y1, int x2, int y2) {
	ll ans = pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1];
	return ans;
}

void solve() {
   	int n, q;
	cin >> n >> q; 

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) cin >> m[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + m[i][j];
			px[i][j] = px[i][j - 1] + px[i - 1][j] - px[i - 1][j - 1] + m[i][j] * (i - 1);
			py[i][j] = py[i][j - 1] + py[i - 1][j] - py[i - 1][j - 1] + m[i][j] * (j - 1);
		}
	}


	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// cout << (rect(px, x1, y1, x2, y2) - (y1 - 1) * rect(p, x1, y1, x2, y2)) << endl;
		ll ans = rect(p, x1, y1, x2, y2);
		ans += (y2 - y1 + 1) * (rect(px, x1, y1, x2, y2) - (x1 - 1) * rect(p, x1, y1, x2, y2));
		// cout << (y2 - y1 + 1) * (rect(px, x1, y1, x2, y2) - (y1 - 1) * rect(p, x1, y1, x2, y2)) << endl;
		ans += rect(py, x1, y1, x2, y2);
		ans -= (y1 - 1) * rect(p, x1, y1, x2, y2);
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    