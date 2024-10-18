#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& win) {
    for (int v : adj[u]) if (v != p) dfs(v, u, adj, win);

    for (int v : adj[u]) if (v != p && !win[v]) win[u]++;
}

void find_win(int u, int p, vector<vector<int>>& adj, vector<int>& win, vector<bool>& act_win) {
    if (win[u]) act_win[u] = true;
    
    for (int v : adj[u]) if (v != p) {
        bool changed = false;
        if (win[u] == 0 || (win[u] == 1 && !win[v])) {
            changed = true;
            win[v]++;
        }
        find_win(v, u, adj, win, act_win);
    }
}

void solve() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> win(n);
    
    dfs(0, -1, adj, win);

    vector<bool> act_win(n);
    find_win(0, -1, adj, win, act_win);

    while (t--) {
        int x;
        cin >> x; x--;
        cout << (act_win[x] ? "Ron" : "Hermione") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
