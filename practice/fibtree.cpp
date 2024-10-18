// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

// if we check a subtree, we need to see either, if it works, or if it definitely does not wor
// for a subtree, return true if it does work, otherwise return check if it will work

vector<set<int>> adj;
vector<int> fib, sz, par;

bool dfs(int u, int p, int id, int root) {
	if (adj[u].size() == 0) return true; // we are in a tree of size 1
	for (int v : adj[u]) {
		if (v == p) continue;
		if (sz[v] == fib[id - 1]) {
			adj[u].erase(v);
			adj[v].erase(u);
			int cur = u;
			while (cur != root) {
				sz[cur] -= sz[v];
				cur = par[cur];
			}
			sz[cur] -= sz[v];
			dfs(root, -1, id - 2, root);
			dfs(v, -1, id - 1, v);
			return true;
		}
		else if (sz[v] == fib[id - 2]) {
			adj[u].erase(v);
			adj[v].erase(u);
			int cur = u;
			while (cur != root) {
				sz[cur] -= sz[v];
				cur = par[cur];
			}
			sz[cur] -= sz[v];
			dfs(root, -1, id - 1, root);
			dfs(v, -1, id - 2, v);
			return true;
		}
		else if (dfs(v, u, id, root)) return true; // v might already be gone from another dfs, but how will it be gone?
	}
	return false;
}

void find_sz(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		par[v] = u;
		find_sz(v, u);
		sz[u] += sz[v];
	}
}

int main() {
	int n;
	cin >> n;

	fib = {0, 1};
	while (fib.back() < n) fib.push_back(fib.back() + fib[fib.size() - 2]);
	if (n != fib.back()) {
		cout << "NO\n";
		return 0;
	}

	adj.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	sz.resize(n + 1);
	par.resize(n + 1);
	find_sz(1, -1);

	dfs(1, -1, fib.size() - 1, 1);

	bool ans = true;
	for (int i = 1; i <= n; i++) if (sz[i] != 1) ans = false;

	cout << (ans ? "YES\n" : "NO\n");
}
