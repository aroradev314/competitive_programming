#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void ckmin(ll& cur, ll cand) {
	if (cand == -1) return;
	if (cur == -1 || cand < cur) cur = cand;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<ll> pref(n + 1);
    vector<int> b(m + 1);

    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	pref[i] = a[i] + pref[i - 1];
    }
    for (int i = 1; i <= m; i++) cin >> b[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
	
	for (int i = 0; i <= m; i++) dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] > b[j]) continue;
			dp[i][j] = dp[i][j - 1];
			int l = 1, r = i;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (pref[i] - pref[mid - 1] > b[j]) l = mid + 1;
				else r = mid - 1;
			}
			if (dp[r][j] != -1) ckmin(dp[i][j], m - j + dp[r][j]);
			if (dp[r][j - 1] != -1) ckmin(dp[i][j], m - j + dp[r][j - 1]);
		}
	}
	ll ans = -1;
	for (int i = 1; i <= m; i++) ckmin(ans, dp[n][i]);
	// for (int i = 1; i <= m; i++) cout << dp[n][i] << " ";
	//cout << endl;
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    