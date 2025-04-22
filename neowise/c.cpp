#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1010;
int h[MAX_N][MAX_N];
int a[MAX_N];
int b[MAX_N];
ll dp[MAX_N][2];

ll c_min(ll x, ll y) {
	if (x == -1) return y;
	else if (y == -1) return x;
	else return min(x, y);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> h[i][j];
		}
	}

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = a[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
		int lo = 0, eq = 0, hi = 0;
		for (int j = 1; j <= n; j++) {
			if (h[i][j] == h[i - 1][j]) eq++;
			else if (h[i][j] + 1 == h[i - 1][j]) lo++;
			else if (h[i][j] == h[i - 1][j] + 1) hi++;
		}

		// we don't adjust this row
		if (eq == 0) {
			dp[i][0] = c_min(dp[i][0], dp[i - 1][0]);
		}
		if (hi == 0) {
			dp[i][0] = c_min(dp[i][0], dp[i - 1][1]);
		}
		// we increase this row and we don't increase the last one
		if (lo == 0 && dp[i - 1][0] != -1) {
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		if (eq == 0 && dp[i - 1][1] != -1) {
			dp[i][1] = c_min(dp[i][1], dp[i - 1][1] + a[i]);
		}
		// if (i == 2) {
		// 	cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
		// 	cout << lo << " " << eq << " " << hi << endl;
		// }
	}

	ll ans1 = c_min(dp[n][0], dp[n][1]);
	if (ans1 == -1) {
		cout << "-1\n";
		return;
	}

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = b[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
		int lo = 0, eq = 0, hi = 0;
		for (int j = 1; j <= n; j++) {
			if (h[j][i] == h[j][i - 1]) eq++;
			else if (h[j][i] + 1 == h[j][i - 1]) lo++;
			else if (h[j][i] == h[j][i - 1] + 1) hi++;
		}

		// we don't adjust this row
		if (eq == 0) {
			dp[i][0] = c_min(dp[i][0], dp[i - 1][0]);
		}
		if (hi == 0) {
			dp[i][0] = c_min(dp[i][0], dp[i - 1][1]);
		}
		// we increase this row and we don't increase the last one
		if (lo == 0 && dp[i - 1][0] != -1) {
			dp[i][1] = dp[i - 1][0] + b[i];
		}
		if (eq == 0 && dp[i - 1][1] != -1) {
			dp[i][1] = c_min(dp[i][1], dp[i - 1][1] + b[i]);
		}
	}

	ll ans2 = c_min(dp[n][0], dp[n][1]);
	if (ans2 == -1) {
		cout << "-1\n";
		return;
	}

	cout << ans1 + ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    