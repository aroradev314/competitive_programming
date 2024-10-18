#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 1e5 + 10;
const int MAX_K = 12;
const ll INF = 2e17;

priority_queue<ll> cur[MAX_N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
    }

    priority_queue<pair<ll, int>> pq; // dist, index

    pq.push({0, 1});
    cur[1].push(0);

    while (!pq.empty()) {
        auto [x, u] = pq.top();
        pq.pop();
        x = -x;
        if (x > cur[u].top()) continue; 
        
        for (auto [v, t] : adj[u]) {
            ll tmp = x + t;
            if (cur[v].size() < k) {
                cur[v].push(tmp);
                pq.push({-tmp, v});
            }
            else if (cur[v].top() > tmp) {
                cur[v].pop();
                cur[v].push(tmp);
                pq.push({-tmp, v});
            }
        }
    }

    vector<ll> ans;
    while (cur[n].size()) {
        ans.push_back(cur[n].top());
        cur[n].pop();
    }

    for (int i = k - 1; i >= 0; i--) cout << ans[i] << " ";

}
