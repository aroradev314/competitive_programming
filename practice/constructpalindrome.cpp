#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1010;
const int INF = 2e9;
vector<pair<int, int>> adj[MAX_N];
int dist[MAX_N][MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b, a--, b--;
		cin >> c;
		c -= 'a';
		adj[a].push_back({b, c});
		if (a != b) adj[b].push_back({a, c});
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			dist[i][j] = INF;
	}

	priority_queue<array<int, 3>> pq;
	dist[0][n - 1] = 0;
	pq.push({0, 0, n - 1});

	while (!pq.empty()) {
		auto [d, x, y] = pq.top();
		pq.pop();
		d = -d;
		if (dist[x][y] != d) continue;

		for (auto [j, c1] : adj[x]) {
			if (j == y) dist[y][y] = min(dist[y][y], dist[x][y] + 1);
			for (auto [k, c2] : adj[y]) {
				if (c1 != c2) continue;
				if (dist[x][y] + 2 < dist[j][k]) {
					dist[j][k] = dist[x][y] + 2;
					if (j != k) pq.push({-dist[j][k], j, k});
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < n; i++) ans = min(ans, dist[i][i]);
	cout << (ans == INF ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    