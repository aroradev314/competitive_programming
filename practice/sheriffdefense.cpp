#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
int a[MAX_N];
ll dp[MAX_N][2];

int n, x;

void dfs(int u, int p) {
    for (int c : adj[u]) if (c != p) dfs(c, u);

    dp[u][0] = 0;
    dp[u][1] = a[u];

    for (int c : adj[u]) if (c != p) {
        dp[u][0] += max(dp[c][0], dp[c][1]);
        dp[u][1] += max(dp[c][0], dp[c][1] - 2LL * x);
    }
}

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int first, second;
        cin >> first >> second;
        first--; second--;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << "\n";

    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
