#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 1e5 + 10;
vector<int> adj[MAX_N], tree_adj[MAX_N];
bool visited[MAX_N];
int dp[MAX_N], sz[MAX_N];

int n, m;
ll ans;


void construct_tree(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree_adj[u].push_back(v);
            construct_tree(v);
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    sz[u] = 1;
    int up = 0;
    for (int v : adj[u]) if (visited[v]) up++;
    up--; // parent does not count as a back edge going up

    int tot = 0;
    for (int v : tree_adj[u]) {
        dfs(v);
        tot += dp[v];
        sz[u] += sz[v];
    }

    int down = adj[u].size() - tree_adj[u].size() - up - 1;
    dp[u] = up + tot - down;
    if (dp[u] == 0) ans = max(ans, sz[u] * 1LL * (n - sz[u]));
}

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    construct_tree(1);
    for (int i = 1; i <= n; i++) visited[i] = false;
    
    ans = 0;
    dfs(1);

    ll pairs = (n * 1LL * (n - 1)) / 2 - ans;
    
    cout << pairs << "\n";


    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        tree_adj[i].clear();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
