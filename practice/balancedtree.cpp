#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int n;
vector<int> adj[MAX_N];
int l[MAX_N], r[MAX_N];
int a[MAX_N];
ll ans;

void dfs(int u, int p) {
	a[u] = l[u];
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		a[u] = max(a[u], a[v]);
	}
	a[u] = min(a[u], r[u]);

	for (int v : adj[u]) if (v != p) {
		ans += max(a[v] - a[u], 0);
	}
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = 0;
	dfs(0, -1);
	ans += a[0];

	cout << ans << "\n";

	for (int i = 0; i < n; i++) adj[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    