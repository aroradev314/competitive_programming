#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

int n, MOD;

const int MAX_N = 1e5 + 10;
vector<int> adj[MAX_N];
int dp[MAX_N];
int fin[MAX_N];
int s[MAX_N]; // s[u] sum of 1 + dp[v] for all children v of u
// then when we want to we can just subtract from 

int add(int a, int b) {
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;

	return a;
}

int mul(int a, int b) {
	return (int) ((a * 1LL * b) % MOD);
}

int sub(int a, int b) {
	return add(a, -b);
}

int binexp(int a, int b) {
	if (b == 0) return 1;
	int ans = binexp(a, b / 2);
	ans = mul(ans, ans);
	if (b % 2) ans = mul(ans, a);
	return ans;
}

int inv(int a) {
	return binexp(a, MOD - 2);
}

void dfs(int u, int p) {
	dp[u] = 1;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		dp[u] = mul(dp[u], 1 + dp[v]);
		s[u] = add(s[u], 1 + dp[v]);
	}
}

void find(int u, int p) {
	for (int v : adj[u]) if (v != p) {
		
	}
}

void solve() {
    cin >> n >> MOD;

    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v, u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    dfs(0, -1);
    find(0, -1);

    for (int i = 0; i < n; i++) cout << fin[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    