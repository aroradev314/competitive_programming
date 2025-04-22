#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 60;
const ll INF = 2e18;
ll dp[MAX_N][MAX_N][MAX_N];

bool on(ll a, int pos) {
	return (a & (1LL << pos));
}

void solve() {
	ll x, y;
	cin >> x >> y;

	ll ans = INF;
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			if ((x >> i) == (y >> j)) ans = min(ans, dp[i][j][MAX_N - 1]);
		}
	}
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			if (i == 0 && j == 0) continue;
			dp[i][j][0] = INF;
			for (int k = 1; k < MAX_N; k++) {
				ll cost = (1LL << k);
				dp[i][j][k] = dp[i][j][k - 1];
				if (k <= i && dp[i - k][j][k - 1] != INF) dp[i][j][k] = min(dp[i][j][k], dp[i - k][j][k - 1] + cost);
				if (k <= j && dp[i][j - k][k - 1] != INF) dp[i][j][k] = min(dp[i][j][k], dp[i][j - k][k - 1] + cost);
			}
		}
	}

    int t;
    cin >> t;
    while (t--) solve();
}
    