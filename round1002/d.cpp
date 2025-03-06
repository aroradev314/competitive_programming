#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1010;
set<int> adj[2][MAX_N];

ll dist[MAX_N][MAX_N][2];
bool visited[MAX_N][MAX_N][2];

const ll INF = 1e18;

void solve() {
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	s1--;
	s2--;

	int m1, m2;
	cin >> m1;
	for (int i = 0; i < m1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		adj[0][a].insert(b);
		adj[0][b].insert(a);
	}

	cin >> m2;
	for (int i = 0; i < m2; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		adj[1][a].insert(b);
		adj[1][b].insert(a);
	}

	vector<bool> valid(n);
	for (int i = 0; i < n; i++) {
		for (int j : adj[0][i]) {
			if (adj[1][i].count(j)) {
				valid[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < 2; k++) {
		dist[i][j][k] = INF;
		visited[i][j][k] = false;
	}
	priority_queue<array<ll, 4>> pq;
	dist[s1][s2][0] = 0;
	pq.push({0, s1, s2, 0});

	while (!pq.empty()) {
		auto [d, x, y, p] = pq.top();
		d = -d;
		pq.pop();

		if (visited[x][y][p]) continue;

		visited[x][y][p] = true;
		for (int u : adj[0][x]) {
			for (int v : adj[1][y]) {
				if (d + abs(u - v) < dist[u][v][1 - p]) {
					dist[u][v][1 - p] = d + abs(u - v);
					pq.push({-dist[u][v][1 - p], u, v, 1 - p});
				}
			}
		}
	}

	ll ans = INF;
	for (int i = 0; i < n; i++) {
		if (valid[i]) {
			ans = min(ans, dist[i][i][0]);
			ans = min(ans, dist[i][i][1]);
		}
	}

	cout << (ans == INF ? -1 : ans) << "\n";

	for (int i = 0; i < n; i++) {
		adj[0][i].clear();
		adj[1][i].clear();
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    