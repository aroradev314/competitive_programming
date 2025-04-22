#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 35;
char c[MAX_N][2];
int a[MAX_N][2];
ll dp[MAX_N][2];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> c[i][0] >> a[i][0] >> c[i][1] >> a[i][1];

    // dp[i][j] is how many people we can make from putting 1 person in the (i,j)th gate
    dp[n][0] = dp[n][1] = 1;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = dp[i + 1][j];
			if (c[i][j] == 'x') dp[i][j] += (a[i][j] - 1) * max(dp[i + 1][j], dp[i + 1][1 - j]);
			else ans += a[i][j] * max(dp[i + 1][j], dp[i + 1][1 - j]);
		}
    }
    ans += dp[0][0];
    ans += dp[0][1];

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    