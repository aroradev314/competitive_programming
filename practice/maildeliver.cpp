#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
   	for (int i = 0; i < m; i++) {
   		int a, b;
   		cin >> a >> b;
   		adj[a].push_back({b, i});
   		adj[b].push_back({a, i});
   		deg[a]++;
   		deg[b]++;
   	}  
   	for (int i = 1; i <= n; i++) {
   		if (deg[i] % 2) {
   			cout << "IMPOSSIBLE\n";
   			return;
   		}
   	}

   	stack<int> s;
   	vector<int> path;
   	s.push(1);
   	vector<bool> seen(m);
   	while (!s.empty()) {
   		int u = s.top();
   		if (deg[u] == 0) {
   			path.push_back(u);
   			s.pop();
   		}
   		else {
   			while (sz(adj[u]) && seen[adj[u].back().second]) adj[u].pop_back();
   			auto [v, i] = adj[u].back();
   			adj[u].pop_back();
   			s.push(v);
   			deg[v]--;
   			deg[u]--;
   			seen[i] = true;
   		}
   	}
   	reverse(path.begin(), path.end());
   	if (sz(path) != m + 1 || path.back() != 1) {
   		cout << "IMPOSSIBLE\n";
   		return;
   	}
   	for (int i : path) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    