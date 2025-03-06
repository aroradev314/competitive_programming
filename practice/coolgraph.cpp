#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
set<int> adj[MAX_N];

struct DSU {
    vector<int> pr;
    vector<int> siz;
    int n;
 
    DSU(int x) : n(x) {
        pr.resize(n);
        siz.resize(n, 1);
        iota(pr.begin(), pr.end(), 0);
    }
 
    inline int findpr(int v) {
        while (v != pr[v]) v = pr[v];
        return v;
    }

    inline int get_sz(int v) {
    	return siz[findpr(v)];
    }
 
    inline bool unite(int v, int u) {
        if (v < 1 || v > n || u < 1 || u > n) return false;
        v = findpr(v);
        u = findpr(u);

        if (siz[u] < siz[v]) swap(u, v);

        if (u == v) {
            return false;
        } else {
            pr[v] = u;
            siz[u] += siz[v];
            return true;
        }
    }
};

void dfs(int u, int p, DSU& dsu) {
	for (int v : adj[u]) if (v != p) {
		dsu.unite(u, v);
		dfs(v, u, dsu);
	}
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }

    vector<array<int, 3>> ops;

    for (int i = 1; i <= n; i++) {
    	while (sz(adj[i]) >= 2) {
    		int a = *adj[i].begin();
    		adj[i].erase(adj[i].begin());
    		int b = *adj[i].begin();
    		adj[i].erase(adj[i].begin());
    		adj[a].erase(i);
    		adj[b].erase(i);

    		if (adj[a].count(b)) {
    			adj[a].erase(b);
    			adj[b].erase(a);
    		}
    		else {
    			adj[a].insert(b);
    			adj[b].insert(a);
    		}

    		ops.push_back({i, a, b});
    	}
    }

   	bool found = false;
   	for (int i = 1; i <= n; i++) if (sz(adj[i])) {
   		found = true;
   		break;
   	}

   	if (!found) {
   		cout << sz(ops) << "\n";
   		for (auto i : ops) {
   			for (int j : i) cout << j << " ";
   			cout << "\n";
   		}
   		for (int i = 1; i <= n; i++) adj[i].clear();
   		return;
   	}

   	// do a dfs for each node that has an adjacency list of size greater than 1
   	// for (int i = 1; i <= 3; i++) {
   	// 	cout << i << ": ";
   	// 	for (int j : adj[i]) cout << j << " ";
   	// 	cout << endl;
   	// }

   	DSU dsu(n + 1);
   	int a = -1, b = -1;
   	for (int i = 1; i <= n; i++) {
   		if (a == -1 && sz(adj[i])) {
   			a = i;
   			b = *adj[i].begin();
   		}
   		if (dsu.get_sz(i) == 1) dfs(i, i, dsu); 
   	}

   	for (int i = 1; i <= n; i++) {
   		bool diff = dsu.unite(a, i);
   		if (diff) {
   			ops.push_back({a, b, i});
   			b = i;
   		}
   	}

   	cout << sz(ops) << "\n";
	for (auto i : ops) {
		for (int j : i) cout << j << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) adj[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    