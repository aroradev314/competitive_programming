#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool near[MAX_N]; // adjacent to a leaf
int dp[MAX_N]; // dp[i] is number of vertices in this subtree that are a safe candidate for p if i is q

ll ans, not_leaves;

void dfs(int u, int p) {
	if (!near[u]) dp[u] += 1;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		dp[u] += dp[v];
	}
}

void find_ans(int u, int p) {
	for (int v : adj[u]) if (v != p) {
		if (near[v] && deg[u] > 1) {
			// if (dp[v] > 0) cout << u << " " << v << endl;
			ans += dp[v];
		}
		find_ans(v, u);
	}

	if (deg[u] != 1 && p != -1 && near[p]) {
		// cout << u << " " << p << " " << dp[1] - dp[p] << "\n";
		ans += (dp[1] - dp[u]);
	}

	if (deg[u] == 1) ans += not_leaves;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b;
    	deg[a]++;
    	deg[b]++;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    not_leaves = 0;
    for (int i = 1; i <= n; i++) if (deg[i] != 1) not_leaves++;

    for (int i = 1; i <= n; i++) {
    	if (deg[i] == 1) near[i] = true;
    	for (int j : adj[i]) if (deg[j] == 1) {
    		near[i] = true;
    		break;
    	}
    }

    dfs(1, -1);
    // for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    // cout << endl;

    ans = 0;
	find_ans(1, -1);
	
	cout << ans << "\n";

	for (int i = 1; i <= n; i++) {
		deg[i] = 0;
		adj[i].clear();
		near[i] = false;
		dp[i] = 0;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    