#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e17;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<bool> horse(n + 1);
    
    for (int i = 0; i < x; i++) {
        int id; cin >> id;
        horse[id] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<vector<ll>> dist1(n + 1, vector<ll>(2, INF));
    vector<vector<ll>> dist2(n + 1, vector<ll>(2, INF));
    vector<vector<bool>> vis(n + 1, vector<bool>(2));
    priority_queue<array<ll, 3>> pq;

    dist1[1][0] = 0;
    pq.push({0, 1, 0}); // -dist, vertex, horse

    while (!pq.empty()) {
        auto [d, v, h] = pq.top();
        d = -d;
        pq.pop();
        if (vis[v][h]) continue;
        vis[v][h] = true;

        if (h == 0 && horse[v]) {
            if (d < dist1[v][1]) {
                dist1[v][1] = d;
                pq.push({-d, v, 1});
            }
        }

        for (auto [u, w] : adj[v]) {
            ll add = d + (h ? (w / 2) : w);
            if (add < dist1[u][h]) {
                dist1[u][h] = add;
                pq.push({-add, u, h});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        vis[i][0] = false;
        vis[i][1] = false;
    }

    dist2[n][0] = 0;
    pq.push({0, n, 0});

    while (!pq.empty()) {
        auto [d, v, h] = pq.top();
        d = -d;
        pq.pop();
        if (vis[v][h]) continue;
        vis[v][h] = true;

        if (h == 0 && horse[v]) {
            if (d < dist2[v][1]) {
                dist2[v][1] = d;
                pq.push({-d, v, 1});
            }
        }

        for (auto [u, w] : adj[v]) {
            ll add = d + (h ? (w / 2) : w);
            if (add < dist2[u][h]) {
                dist2[u][h] = add;
                pq.push({-add, u, h});
            }
        }
    }
    
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ll first = min(dist1[i][0], dist1[i][1]);
        ll second = min(dist2[i][0], dist2[i][1]);
        if (first != INF && second != INF) ans = min(ans, max(first, second));
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
