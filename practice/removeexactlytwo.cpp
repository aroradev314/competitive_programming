#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
set<int> adj[MAX_N];
set<pair<int, int>> m;
int ans;

void dfs(int u, int p) {
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
	}

	vector<int> d;
	m.erase({sz(adj[u]) - 1, u});
	for (int v : adj[u]) {
		m.erase({sz(adj[v]) - 1, v});
		m.insert({sz(adj[v]) - 2, v});
	}
	ans = max(ans, sz(adj[u]) + (*(--m.end())).first);

	m.insert({sz(adj[u]) - 1, u});
	for (int v : adj[u]) {
		m.insert({sz(adj[v]) - 1, v});
		m.erase({sz(adj[v]) - 2, v});
	}
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].insert(b);
    	adj[b].insert(a);
    }

    m.clear();
    for (int i = 1; i <= n; i++) m.insert({sz(adj[i]) - 1, i});

    ans = 0;
    dfs(1, -1);

    cout << ans << "\n";

    for (int i = 1; i <= n; i++) {
    	adj[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    