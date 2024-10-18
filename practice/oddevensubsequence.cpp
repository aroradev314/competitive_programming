#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = 1e9;

    while (l <= r) {
        int c = l + (r - l) / 2;

        // dp[i][0] - max length of even indices
        // dp[i][1] - max length of odd indices
        // mx_even is the 
        
        vector<vector<int>> dp(n + 1, vector<int>(2));

        if (a[1] <= c) dp[1][1] = 1;
        
        int mx_odd = 0, mx_even = 0;
        
        // mx_odd is the max length of the subsequence that has to be of odd length 

        for (int i = 2; i <= n; i++) {
            if (a[i] <= c) {
                if (!(i == n && k % 2 == 0)) dp[i][1] = mx_odd + 1;
                if (!(i == n && k % 2 == 1)) dp[i][0] = mx_even + 1;
            }
            mx_odd = max(mx_odd, dp[i - 1][1]);
            mx_even = max(mx_even, dp[i - 1][0]);
        }

        mx_odd = max(mx_odd, dp[n][1]);
        mx_even = max(mx_even, dp[n][0]);


        if (mx_even >= k / 2 || mx_odd >= k / 2 + k % 2) r = c - 1;
        else l = c + 1;
    }

    cout << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
