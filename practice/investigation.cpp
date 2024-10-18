#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
    }

    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});

    vector<ll> dist(n + 1, -1), num(n + 1), mn(n + 1), mx(n + 1);
    dist[1] = 0;
    num[1] = 1;
    vector<bool> seen(n + 1); 
    while (!pq.empty()) {
        auto [x, u] = pq.top();
        x = -x;
        pq.pop();
        
        if (seen[u]) continue;
        seen[u] = true;

        for (auto [v, c] : adj[u]) {
            if (dist[v] == -1 || x + c < dist[v]) {
                dist[v] = x + c;
                num[v] = num[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({-dist[v], v});
            }
            else if (x + c == dist[v]) {
                (num[v] += num[u]) %= MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << num[n] << " " << mn[n] << " " << mx[n];
    
}
