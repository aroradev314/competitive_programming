#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> a;
vector<vector<pair<int, int>>> adj;
vector<int> par, price;

// vector<array<int, 3>> ops; // ops[i] will store the operations that have been done to vertex i
vector<map<int, ll>> groups;

void dfs(int u, int p) {
    for (auto [v, c] : adj[u]) if (v != p) {
        par[v] = u;
        price[v] = c;
        dfs(v, u);
    }
}

void dfs2(int u, ll& total) {
    for (auto [v, c] : adj[u]) if (v != par[u]) {
        if (a[u] != a[v]) total += c;
        groups[u][a[v]] += c;
        dfs2(v, total);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    adj.clear();
    adj.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c, u--, v--;    
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    par.resize(n);
    price.resize(n);
    par[0] = -1;
    dfs(0, -1);

    ll total = 0;
    groups.clear();
    groups.resize(n);
    dfs2(0, total);


    while (q--) {
        int u, x;
        cin >> u >> x, u--;

        if (par[u] != -1) {
            if (a[par[u]] != a[u]) total -= price[u];
            if (a[par[u]] != x) total += price[u];
            groups[par[u]][a[u]] -= price[u];
            groups[par[u]][x] += price[u];
        }

        total += groups[u][a[u]];
        total -= groups[u][x];

        cout << total << "\n";

        a[u] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    