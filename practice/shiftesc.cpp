#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 210;
ll dp[MAX_N][MAX_N][MAX_N];
ll mn[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

void solve() {
	int n, m; 
	ll x;
	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mn[i][j] = LLONG_MAX;
			for (int k = 0; k < m; k++) {
				dp[i][j][k] = LLONG_MAX;
				ll s = a[i][1 + ((j - 1) + k) % m];
				if (j > 1) dp[i][j][k] = dp[i][j - 1][k] + s;
				if (i > 1 || (i == 1 && j == 1)) dp[i][j][k] = min(dp[i][j][k], mn[i - 1][j] + x * k + s);
				mn[i][j] = min(mn[i][j], dp[i][j][k]);
			}
		}
	}

	cout << mn[n][m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    