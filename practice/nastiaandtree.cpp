#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
set<int> adj[MAX_N];
vector<pair<int, int>> removed;
vector<int> garbage[MAX_N];

bool visited[MAX_N];


int a, b;

void dfs(int u, int p) {
    for (int v : adj[u]) if (v != p) dfs(v, u);
    
    for (int v : garbage[u]) adj[u].erase(v);
    
    int c = sz(adj[u]) - (p == -1 ? 0 : 1);
    if (c == 2 && p != -1) {
        adj[u].erase(p);
        garbage[p].push_back(u);
        removed.push_back({u, p});
    }
    else if (c > 2) {
        if (p != -1) {
            adj[u].erase(p);
            garbage[p].push_back(u);
            removed.push_back({u, p});
        }

        while (c > 2) {
            int er = *adj[u].begin();
            adj[u].erase(er);
            adj[er].erase(u);
            removed.push_back({u, er});
            c--;
        }
    }
}

void mark(int u, int p) {
    visited[u] = true;
    if (adj[u].size() == 0) {
        a = u;
        b = u;
    }
    else if (adj[u].size() == 1) {
        if (a == -1) a = u;
        else b = u;
    }

    for (int v : adj[u]) if (v != p) mark(v, u);
}

void solve() {
    int n;
    cin >> n; 
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    dfs(0, -1);

    int oldb = -1;
    cout << sz(removed) << "\n";
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        a = -1, b = -1;
        mark(i, -1);
        
        assert(a != -1 && b != -1);

        if (oldb != -1) {
            auto [x, y] = removed.back();
            cout << x + 1 << " " << y + 1 << " " << oldb + 1 << " " << a + 1 << "\n";
            removed.pop_back();
        }
        oldb = b;
    }
    assert(sz(removed) == 0);

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        garbage[i].clear();
        visited[i] = false;
    }
    removed.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
