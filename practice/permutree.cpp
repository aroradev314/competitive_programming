#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 5050;
int dp[MAX_N];
vector<int> adj[MAX_N];

void dfs(int u) {
	dp[u] = 1;
	for (int v : adj[u]) {
		dfs(v);
		dp[u] += dp[v];
	}
}

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
    	int p;
    	cin >> p;
    	adj[p].push_back(i);
    }

    dfs(1);

    bitset<MAX_N> possible;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
    	int sub = 0;
    	possible.reset();
    	possible[0] = 1;
    	for (int v : adj[i]) {
    		sub += dp[v];
    		possible |= (possible << dp[v]);
    	}

    	ll cur = 0;
    	for (int j = 0; j < MAX_N; j++) if (possible[j]) cur = max(cur, j * 1LL * (sub - j));
    	ans += cur;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    