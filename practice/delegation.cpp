#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
vector<int> adj[MAX_N];
int dp[MAX_N];
bool ans;

void dfs(int u, int p, int k) {
	multiset<int> m;
	dp[u] = 0;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u, k);
		dp[u] += dp[v] + 1; // dp[u] is the edges in the subtree of u
		int left = (dp[v] + 1) % k;
		// if (u + 1 == 8 && k == 4) cout << v + 1 << " " << left << endl;
		if (left) {
			if (m.count(k - left)) m.erase(m.find(k - left));
			else m.insert(left);
		}
	}
	if (sz(m) > 1) ans = false;
}

void solve() {	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> div;
	for (int i = 1; i * i <= n - 1; i++) {
		if ((n - 1) % i == 0) {
			div.push_back(i);
			if (i != (n - 1) / i) div.push_back((n - 1) / i);
		}
	}

	vector<bool> works(n);

	for (int i : div) {
		ans = true;
		dfs(0, -1, i);
		if (ans) works[i] = true;
	}
	for (int i = 1; i < n; i++) cout << works[i];
}

int main() {
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    