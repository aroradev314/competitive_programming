#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    ll v;
    cin >> n >> m >> v;
    vector<ll> cake(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> cake[i]; 
    	pref[i] = pref[i - 1] + cake[i];
    }

    // dp[i][j] is max sections that we can partition up to i, into
    // if j is 0 that means we have not given to alice, otherwise we have 

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][1] = -1;

	ll l = 1, r = pref[n];
	ll ans = -1;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		int alice_left = 0, creature_left = 0;
		ll alice = 0, creature = 0;
		for (int i = 1; i <= n; i++) {
			alice += cake[i];
			creature += cake[i];
	    	while (creature - cake[creature_left] >= v) {
	    		creature -= cake[creature_left];
	    		creature_left++;
	    	}
			while (alice - cake[alice_left] >= mid) {
				alice -= cake[alice_left];
				alice_left++;
			}

			dp[i][1] = dp[i - 1][1];
			if (creature_left != 0 && dp[creature_left - 1][1] != -1) dp[i][1] = max(dp[i][1], 1 + dp[creature_left - 1][1]);

			if (alice_left != 0) dp[i][1] = max(dp[i][1], dp[alice_left - 1][0]);
			if (creature_left != 0) dp[i][0] = max(dp[i - 1][0], 1 + dp[creature_left - 1][0]);
		}

		if (dp[n][1] >= m) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (dp[n][0] >= m) ans = max(ans, 0LL);
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    