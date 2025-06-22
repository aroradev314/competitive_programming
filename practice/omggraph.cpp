#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w, u--, v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }

    vector<int> dp_start(n, INF), dp_end(n, INF);

    dp_start[0] = 0;
    priority_queue<pair<int, int>> pq;
    vector<bool> vis(n);
    pq.push({0, 0});

    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	if (vis[u]) continue;
    	vis[u] = true;

    	for (auto [v, w] : adj[u]) {
    		int nd = max(dp_start[u], w);
    		if (nd < dp_start[v]) {
    			dp_start[v] = nd;
    			pq.push({-nd, v});
    		}
    	}
    }

    vis.assign(n, false);
    dp_end[n - 1] = 0;
    pq.push({0, n - 1});

    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	if (vis[u]) continue;
    	vis[u] = true;

    	for (auto [v, w] : adj[u]) {
    		int nd = max(dp_end[u], w);
    		if (nd < dp_end[v]) {
    			dp_end[v] = nd;
    			pq.push({-nd, v});
    		}
    	}
    }

    // for (int i : dp_start) cout << i << " ";
    // cout << "\n";
    // for (int i : dp_end) cout << i << " ";
    // cout << "\n";

    int ans = INF;
    for (int u = 0; u < n; u++) {
    	for (auto [v, w] : adj[u]) {
    		ans = min(ans, max({dp_start[u], dp_end[v], w}) + w);
    	}
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    