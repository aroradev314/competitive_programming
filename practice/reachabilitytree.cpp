#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> edges;

void dfs(int u, int p, bool towards) {
    for (int v : adj[u]) if (v != p) {
        if (towards) edges.push_back({v, u});
        else edges.push_back({u, v});
        dfs(v, u, !towards);
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    vector<int> deg(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

        deg[a]++;
        deg[b]++;
    }

    int center = -1;
    for (int i = 0; i < n; i++) if (deg[i] == 2) {
        center = i;
        break;
    }
    if (center == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    int a = adj[center][0], b = adj[center][1];
    edges.clear();
    edges.push_back({a, center});
    edges.push_back({center, b});

    dfs(a, center, false);
    dfs(b, center, true);

    for (auto [u, v]: edges) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
