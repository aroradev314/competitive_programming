#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int a[MAX_N];
int c[MAX_N];
vector<int> adj[MAX_N];
bool visited[MAX_N];
ll dp[MAX_N][2]; // dp[i][0 / 1] is if we choose this guy or not

void dfs(int u, int rem) {
	visited[u] = true;
	dp[u][0] = 0;
	dp[u][1] = c[u];
	for (int v : adj[u]) {
		if (v == rem) continue;
		dfs(v, rem);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
	// cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> c[i];

	for (int i = 1; i <= n; i++) {
		if (i != a[i]) adj[a[i]].push_back(i);
		else c[i] = 0;
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		int first = -1, second = -1;
		int u = i;
		while (true) {
			if (visited[a[u]]) {
				first = u;
				second = a[u];
				break;
			}
			visited[u] = true;
			u = a[u];
		}

		ll best;
		if (first != second) {
			// cycle of length 1 ends it
			// if we choose f
			dfs(first, first);
			best = dp[first][1];
			// if we choose s
			dfs(second, second);
			best = min(best, dp[second][1]);
		}
		else {
			dfs(first, -1);
			best = min(dp[first][0], dp[first][1]);
		}

		ans += best;
	}

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    