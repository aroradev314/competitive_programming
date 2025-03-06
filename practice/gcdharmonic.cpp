#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 5050;
const int MAX_V = 1500;
vector<int> adj[MAX_N];
int dp[MAX_N][MAX_V]; // dp[i][j] is min cost to make the subtree of i all divisible by j
int val[MAX_N];
vector<int> cand[MAX_V];
vector<int> primes, cmb;

// dp[u][i] is the min cost for the subtree assuming that u is equal to i
// for each child node, we iterate over all of the nodes that have a gcd that is equal 

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void dfs(int u, int p) {
	for (int i = 0; i < sz(cmb); i++) if (val[u] != cmb[i]) dp[u][i] = cmb[i];
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);

		for (int i = 0; i < sz(cmb); i++) {
			int mn = 2e9;
			for (int j : cand[i]) mn = min(mn, dp[v][j]);
			dp[u][i] += mn;
		}
	}
}

void solve() {
	for (int i = 2; i <= 100; i++) {
		bool works = true;
		for (int j = 2; j * j <= i; j++) if (i % j == 0) works = false;
		if (works) primes.push_back(i);
	}

	for (int i : primes) {
		vector<int> add = {i};
		for (int j : cmb) if (j * i <= 10000) add.push_back(j * i);
		for (int j : add) cmb.push_back(j);
	}


	for (int i = 0; i < sz(cmb); i++) {
		for (int j = 0; j < sz(cmb); j++) {
			if (gcd(cmb[i], cmb[j]) > 1) cand[i].push_back(j);
		}
	}
	
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];

    for (int i = 0; i < n; i++) {
    	for (int j = 2; j <= val[i]; j++) {
    		while (val[i] % (j * j) == 0) val[i] /= j;
    	}
    }

    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	cin >> u >> v, u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    dfs(0, -1);

    int ans = 2e9;
    for (int i = 0; i < sz(cmb); i++) ans = min(ans, dp[0][i]);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    