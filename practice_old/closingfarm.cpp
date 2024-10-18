// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int n;
	vector<int> parent, sz;

	DSU(int x) : parent(x), sz(x, 1) {
		n = x;
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	int find(int x) {
		while (x != parent[x]) x = parent[x];
		return x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		parent[y] = x;
	}
};

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> close(n);
	for (int i = 0; i < n; i++) {
		cin >> close[i];
		close[i]--;
	}

	DSU dsu(n);

	vector<bool> ans(n), on(n);
	set<int> connected;
	for (int i = n - 1; i >= 0; i--) {
		int cur = close[i];
		on[cur] = true;
		set<int> near;
		for (int j : adj[cur]) {
			if (on[j]) {
				near.insert(dsu.find(j));
			}
		}

		// hold a set of current connected components
		// if the size of the set is 1 then its good

		for (int j : near) {
			connected.erase(j);
			dsu.merge(cur, j);
		}
		connected.insert(dsu.find(cur));
		
		ans[i] = (connected.size() == 1);
	}

	for (bool i : ans) {
		cout << (i ? "YES\n" : "NO\n");
	}
}

