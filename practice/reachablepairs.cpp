#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
ll ca;

struct DSU {
	int n;
	vector<int> par, siz, num; 
	vector<bool> on;

	DSU(int x) : n(x), par(n), siz(n, 1), num(n), on(n) {
		iota(par.begin(), par.end(), 0);
	}

	int find(int a) {
		while (a != par[a]) a = par[a];
		return a;
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];

		ca += (num[x] * 1LL * num[y]);
		num[x] += num[y];

		par[y] = x;
	}

	void act(int u) {
		for (int v : adj[u]) if (on[v]) unite(u, v);
	}
};


void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    DSU dsu(n);
    for (int i = 0; i < n; i++) if (s[i] == '1') {
    	dsu.on[i] = true;
    	dsu.act(i);
    }

    // we go through it in reverse, if we find a 0 that means that we activate this one 
    vector<ll> ans(n);
    ca = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (s[i] == '0') {
    		dsu.on[i] = true;
    		dsu.act(i);
    	}
    	dsu.num[dsu.find(i)]++;
    	ca += dsu.num[dsu.find(i)] - 1;
    	ans[i] = ca;
    }

    for (ll i : ans) cout << i << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
    