#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vector<int> win(n + 1, true);
    vector<int> dp(n + 1, 1e8);
    dp[0] = -1;
    int best = 0;

    for (int i = 2; i < n; i++) {
        dp[i - 1] = dp[i - 2] + 1;
        for (int v : radj[i - 1]) dp[i - 1] = min(dp[i - 1], dp[v] + 1);

        for (int v : adj[i - 1]) {
            if (dp[i - 1] + 1 < (v - i)) dp[v] = min(dp[v], dp[i - 1] + 1);
            best = max(best, (v - i) - dp[v]);
        }

        if (best > 0) win[i] = false;
        best--;
    }

    for (int i = 1; i < n; i++) cout << win[i];
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
