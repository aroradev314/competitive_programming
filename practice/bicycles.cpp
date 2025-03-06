#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
#define int long long
typedef long double ld;
using namespace std;

const int MAX_N = 1010;

vector<pair<int, int>> adj[MAX_N];
int s[MAX_N];
int dist[MAX_N][MAX_N]; 
const int INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	for (int i = 1; i <= n; i++) cin >> s[i];

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = INF;
	dist[1][1] = 0;
	
	priority_queue<array<int, 3>> pq; 
	pq.push({0, 1, 1});

	while (!pq.empty()) {
		auto [d, u, b] = pq.top();
		pq.pop();
		d = -d;
		if (d != dist[u][b]) continue;

		for (auto [v, w] : adj[u]) {
			int nb = (s[v] < s[b] ? v : b);
			if (d + w * s[b] < dist[v][nb]) {
				dist[v][nb] = d + w * s[b];
				pq.push({-dist[v][nb], v, nb});
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= n; i++) ans = min(ans, dist[n][i]);

	cout << ans << "\n";

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    