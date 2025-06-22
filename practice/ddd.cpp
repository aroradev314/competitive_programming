#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 2e9;

void solve() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<vector<int>> adj(n);
	vector<int> a(l);
	for (int i = 0; i < l; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y, x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<vector<int>> dist(n, vector<int>(2));
	vector<vector<bool>> vis(n, vector<bool>(2));
	for (int i = 0; i < n; i++) {
		dist[i][0] = INF;
		dist[i][1] = INF;
	}
	dist[0][0] = 0;

	priority_queue<array<int, 3>> pq;
	pq.push({0, 0, 0});

	while (!pq.empty()) {
		auto [d, u, par] = pq.top();
		pq.pop();
		d = -d;
		if (vis[u][par]) continue;
		vis[u][par] = true;

		for (int v : adj[u]) {
			if (d + 1 < dist[v][1 - par]) {
				dist[v][1 - par] = d + 1;
				pq.push({-dist[v][1 - par], v, 1 - par});
			}
		}
	}

	ll longest = 0;
	int min_odd = INF;
	for (int i : a) {
		longest += i;
		if (i % 2 == 1) min_odd = min(min_odd, i);
	}

	int a_par = longest % 2;
	for (int i = 0; i < n; i++) {
		if (longest >= dist[i][a_par]) cout << 1;
		else if (min_odd != INF && longest - min_odd >= dist[i][1 - a_par]) cout << 1;
		else cout << 0;
	}
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    