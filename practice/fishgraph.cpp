#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> adj(n);


    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    // do a dfs starting from every node that has deg >= 4
    // if we encounter a cycle that ends back at this node, keep cycling through prev node and marking the nodes
    // then find 2 extra nodes that aren't marked 
    

    for (int u = 0; u < n; u++) {
        if (deg[u] < 4) continue;

        for (int v : adj[u]) {
            queue<int> q;
            vector<int> prev(n, -1);
            prev[v] = u;
            q.push(v);

            while (!q.empty()) {
                int cur = q.front();

                // if (u + 1 == 4 && v + 1 == 1) cout << cur << endl;
                q.pop();
                for (int i : adj[cur]) {
                    if (i == u && cur == v) continue;
                    if (i == u) {
                        // for (int _ : prev) cout << _ + 1 << " ";
                        // cout << endl;
                        cout << "YES\n";
                        vector<pair<int, int>> pairs;
                        pairs.push_back({cur, u});

                        int l = cur;
                        int last = l;
                        while (l != u) {
                            pairs.push_back({prev[l], l});
                            l = prev[l];
                        }

                        int cnt = 0;
                        for (int j = 0; j < adj[i].size() && cnt < 2; j++) {
                            if (adj[u][j] != v && adj[u][j] != last) {
                                pairs.push_back({u, adj[u][j]});
                                cnt++;
                            }
                        }

                        cout << pairs.size() << "\n";
                        for (auto [x, y] : pairs) cout << x + 1 << " " << y + 1 << "\n";
                        return;
                    }
                    else if (prev[i] == -1) {
                        prev[i] = cur;
                        q.push(i);
                    }
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
