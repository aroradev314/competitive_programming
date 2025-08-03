#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = i + 1;
        if (i - 1 >= 0 && a[i - 1] > a[i]) {
            dp[i] = max(dp[i], dp[i - 1] + (i + 1));
        }
        if (i - 2 >= 0 && a[i - 2] > a[i]) {
            dp[i] = max(dp[i], dp[i - 2] + (i + 1) + (a[i - 1] > a[i] ? 1 : 0));
        }
        ans += dp[i];
    }
    // for (int i : dp) cout << i << "\n";

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    