#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
int cnt[MAX_N];
int f[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n * k; i++) {
        int num; cin >> num;
        cnt[num]++;
    }

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        f[num]++;
    }

    vector<int> h(k + 1);
    for (int i = 1; i <= k; i++) cin >> h[i];
    
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        int players = f[i];
        int cards = cnt[i];
    
        if (players == 0 || cards == 0) continue;
    //
        if (players * k <= cards) {
            ans += h[k] * players;
            continue;
        }

        vector<vector<int>> dp(cards + 1, vector<int>(players + 1));
        for (int c = 1; c <= cards; c++) {
            for (int p = 1; p <= players; p++) {
                for (int x = 1; x <= min(c, k); x++) {
                     dp[c][p] = max(dp[c][p], dp[c - x][p - 1] + h[x]);
                }
            }
        }
        ans += dp[cards][players];
    }

    
    cout << ans;
}
