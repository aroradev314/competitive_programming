#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int l = 1, r = 1e9;
    
    vector<int> dp(n);
    while (l <= r) {
        int x = l + (r - l) / 2;
        dp[0] = (a[0] >= x ? 1 : -1);
        for (int i = 1; i < n; i++) {
            int b = (a[i] >= x ? 1 : -1);
            if (i % k == 0) dp[i] = max(dp[i - k], b);
            else {
                dp[i] = dp[i - 1] + b;
                if (i >= k) dp[i] = max(dp[i], dp[i - k]);
            }
        }

        if (dp[n - 1] > 0) l = x + 1;
        else r = x - 1;
    }

    cout << l - 1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
