#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 50500;
const int MAX_K = 510;
vector<int> adj[MAX_N];
ll down[MAX_N][MAX_K];
int n, k;
ll ans;

void dfs(int u, int p) {
	down[u][0] = 1;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);

		for (int i = 1; i <= k; i++) {
			ans += (down[u][k - i] * down[v][i - 1]);
		}
		for (int i = 1; i <= k; i++) {
			down[u][i] += down[v][i - 1];
		}
	}
}

void solve() {
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = 0;
	dfs(1, -1);
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    