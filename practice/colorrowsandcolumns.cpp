#include <bits/stdc++.h>
using namespace std;

void ckmin(int& x, int check) {
    if (x == -1 || check < x) x = check;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int tot = 0;

            int acur = a[i], bcur = b[i];
            for (int x = 0; x <= j; x++) {
                if (dp[i - 1][j - x] != -1) ckmin(dp[i][j], dp[i - 1][j - x] + tot);
                
                if (acur <= 0 && bcur <= 0) break;
                else if (acur < bcur) {
                    tot += acur;
                    bcur--;
                }
                else {
                    tot += bcur;
                    acur--;
                }
            }
        }
    }
    cout << dp[n][k] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) test_case();
}
