#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
vector<int> scores[MAX_N];

int ans;

// for each x, we can make some new components
// what if we start at 1, take all the ans from each one
int dfs(int u, int p, int comps) {
	int cur = comps;
	int children = (u == 1 ? sz(adj[u]) : sz(adj[u]) - 1);
	// we remove from the root up till i
	cur = max(cur, children + comps);

	cur = max(cur, sz(adj[u])); // just remove this vertex
	for (int v : adj[u]) {
		if (v == p) continue;
		int score = dfs(v, u, comps + children - 1);
		// remove from u till the best paths of v
		cur = max(cur, score - comps + (u != 1 ? 1 : 0));
		scores[u].push_back(score - ) 
	}

}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ans = 0;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    