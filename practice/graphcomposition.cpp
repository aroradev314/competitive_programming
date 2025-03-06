#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

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

void solve() {	
	int n, m1, m2;
	cin >> n >> m1 >> m2;

	vector<pair<int, int>> edge(m1);

	DSU f(n + 1), g(n + 1);
	for (int i = 0; i < m1; i++) {
		cin >> edge[i].first >> edge[i].second;
	}

	for (int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		g.unite(u, v);
	}

	int ans = 0;
	for (auto [u, v] : edge) {
		if (g.findpr(u) != g.findpr(v)) ans++;
		else f.unite(u, v);
	}

	set<int> first, second;
	for (int i = 1; i <= n; i++) {
		first.insert(f.findpr(i));
		second.insert(g.findpr(i));
	}

	ans += sz(first) - sz(second);

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    