#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
int dp1[MAX_N], dp2[MAX_N];

void dfs(int u, int p) {
    for (int i : adj[u]) if (i != p) dfs(i, u);

    for (int v : adj[u]) if (v != p) dp2[u] += max(dp1[v], dp2[v]);
    
    for (int v : adj[u]) if (v != p) dp1[u] = max(dp1[u], dp2[v] + 1 + dp2[u] - max(dp1[v], dp2[v]));

    // cout << u + 1 << " " << dp1[u] << " " << dp2[u] << endl;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    
    cout << max(dp1[0], dp2[0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
