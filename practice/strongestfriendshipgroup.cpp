#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct DSU {
	int n;
	vector<int> par, siz;
	DSU(int N) : n(N), par(n), siz(n, 1) {
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) {
		while (x != par[x]) x = par[x];
		return x;
	}

	int same(int x, int y) {
		return find(x) == find(y);
	}

	void unite(int x, int y) {
		if (same(x, y)) return;
		x = find(x);
		y = find(y);

		if (siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
	}
};

const int MAX_N = 1e5 + 10;
set<int> adj[MAX_N];
int deg[MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
		deg[a]++;
		deg[b]++;
	}

	ll ans = 0;
	vector<int> nodes(n);
	vector<vector<int>> node_list;
	vector<bool> visited(n);
	iota(nodes.begin(), nodes.end(), 0);

	DSU dsu(n);
	for (int i = 1; i <= m; i++) {
		vector<int> new_nodes;
		queue<int> q;
		for (int u : nodes) if (sz(adj[u]) < i) {
			q.push(u);
			visited[u] = true;
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : adj[u]) {
				adj[v].erase(u);
				if (!visited[v] && sz(adj[v]) < i) {
					visited[v] = true;
					q.push(v);
				}
			}
		}

		for (int u : nodes) if (!visited[u]) new_nodes.push_back(u);
		nodes = new_nodes;

		node_list.push_back(nodes);
	}

	for (int i = 0; i < n; i++) visited[i] = false;
	int biggest = 0;
	for (int i = m - 1; i >= 0; i--) {
		for (int u : node_list[i]) {
			if (visited[u]) continue;
			visited[u] = true;
			for (int v : adj[u]) dsu.unite(u, v);
			biggest = max(biggest, dsu.siz[dsu.find(u)]);
		}

		ans = max(ans, (i + 1) * 1LL * biggest);
	}

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    