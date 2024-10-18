#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct Edge {
    int node, bus, walk;
};

const int MAX_N = 1e5 + 10;
int n, m;
int t0, t1, t2;

vector<Edge> adj[MAX_N];
int latest[MAX_N];
bool visited[MAX_N];

void solve() {
    cin >> n >> m >> t0 >> t1 >> t2;
    
    for (int i = 0; i < m; i++) {
        int u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        u--;
        v--;
        adj[u].push_back({v, l1, l2});
        adj[v].push_back({u, l1, l2});
    }

    latest[n - 1] = t0;
    for (int i = 0; i < n - 1; i++) latest[i] = -1;

    priority_queue<pair<int, int>> pq;
    pq.push({t0, n - 1});
    while (!pq.empty()) {
        auto [time, u] = pq.top();
        pq.pop();
        if (time <= 0) break;
        if (visited[u]) continue;
        visited[u] = true;

        for (Edge v : adj[u]) {
            // cout << v.bus << " " << v.walk << "\n";
            int bus_end = time - v.bus;
            bool intersects = !(bus_end >= t2 || time <= t1);

            int added = v.bus;
            if (intersects) {
                added = min(v.walk, time - t1 + v.bus);
            }

            if (time - added > latest[v.node]) {
                latest[v.node] = time - added;
                pq.push({latest[v.node], v.node});
            }
        }
    }
    cout << (latest[0] >= 0 ? latest[0] : -1) << "\n";

    for (int i = 0; i < n; i++) {
        adj[i].clear();
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
