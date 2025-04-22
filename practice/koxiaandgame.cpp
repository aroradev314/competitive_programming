#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
const int MOD = 998244353;
int a[MAX_N], b[MAX_N];
vector<int> adj[MAX_N];
bool seen[MAX_N];
bool self;
int n;

void dfs(int u, int& sz, int& edges) {
	seen[u] = true;
	sz++;
	edges += sz(adj[u]);
	for (int v : adj[u]) {
		if (!seen[v]) dfs(v, sz, edges);
		else if (v == u) self = true;
	}
}

void clear() {
    for (int i = 0; i < n; i++) {
    	adj[i].clear();
    	seen[i] = false;
    }
}

void solve(int tt) {
    cin >> n; 

    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++) cin >> b[i], b[i]--;

    for (int i = 0; i < n; i++) {
    	adj[a[i]].push_back(b[i]);
    	adj[b[i]].push_back(a[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
    	if (!seen[i]) {
    		int sz = 0, edges = 0;
    		self = false;
    		dfs(i, sz, edges);
    		if (edges / 2 != sz) {
    			cout << "0\n";
    			clear();
    			return;
    		}
    		if (self) ans = (int) ((ans * 1LL * n) % MOD);
    		else ans = (int) ((ans * 2LL) % MOD);
    	}
    }

    cout << ans << "\n";
    clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) solve(tt);
}
    