#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const int MAX_N = 1e4 + 10;
vector<pair<int, ll>> adj[MAX_N];
ll dist[MAX_N];
ll cnt[MAX_N];
ll passing[MAX_N];

int32_t main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    int n, m;
    ll T;
    cin >> n >> m >> T;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }

    vector<int> next(n + 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<bool> seen(n + 1);
        
    for (int i = 1; i <= n; i++) dist[i] = (ll) 2e17;
    
    dist[1] = 0;
    next[1] = -1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [x, u] = pq.top();
        pq.pop();
        if (seen[u]) continue; 
        seen[u] = true;
        
        for (auto [v, t] : adj[u]) {
            if (dist[u] + t < dist[v]) {
                dist[v] = dist[u] + t;
                next[v] = u;
                pq.push({dist[v], v});
            }
            else if (dist[u] + t == dist[v] && u < next[v]) {
                next[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        int cur = i;
        
        while (cur != 1) {
            cnt[cur] += dist[cur] * c[i];
            passing[cur] += c[i];

            cur = next[cur];
        }
    }
    

    for (int i = 1; i <= n; i++) {
        if (T < dist[i]) ans = max(ans, cnt[i] - passing[i] * T);
    }
    
    cout << ans;
}
