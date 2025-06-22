// #include <bits/stdc++.h>
// #define sz(a) ((int)((a).size()))
// typedef long long ll;
// typedef long double ld;
// using namespace std;

// vector<vector<int>> adj;
// vector<int> par;
// vector<bool> used, vis;

// pair<int, int> dfs(int u, int p) {
// 	pair<int, int> ans = {1, u};
// 	par[u] = p;
// 	seen[u] = true;

// 	for (int v : adj[u]) if (!used[v] && v != p) {
// 		pair<int, int> x = dfs(v, u);
// 		x.first++; // we have one more node
// 		ans = max(ans, x);
// 	}

// 	return ans;
// }

// void solve() {
//     int n;
//     cin >> n;

//     adj = vector<vector<int>>(n);
//     par = vector<int>(n);
//     used = vector<bool>(n);

//     for (int i = 0; i < n - 1; i++) {
//     	int a, b;
//     	cin >> a >> b, a--, b--;
//     	adj[a].push_back(b);
//     	adj[b].push_back(a);
//     }

//     vector<int> seq;

//     set<int> s;
//     for (int i = 0; i < n; i++) s.insert(i);
//     int c = 0;
//     while (c < n) {
//     	vis.assign(n, false);

//     	for (int i = 0; i < n; i++) if (!used[i] && !seen[i]) {
//     		auto [d1, j] = dfs(i, -1);
//     		auto [d2, k] = dfs(j, -1);

//     	}
//     }

//     for (int i : seq) cout << i << " ";
//     cout << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) solve();
// }
//     


#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;
 
vector<vector<int>> adj;
vector<int> par, dist;
vector<bool> used, vis;
 
void dfs1(int u, int& d, int& x) {
	vis[u] = true;
	if (dist[u] > d) {
		d = dist[u];
		x = u;
	}
	else if (dist[u] == d && u > x) x = u;
 
	for (int v : adj[u]) if (!used[v] && !vis[v]) {
		dist[v] = dist[u] + 1;
		dfs1(v, d, x);
	}
}
 
void dfs2(int u, int p, int& d, int& y) {
	par[u] = p;
	if (dist[u] > d) {
		d = dist[u];
		y = u;
	}
	else if (dist[u] == d && u > y) y = u;
 
	for (int v : adj[u]) if (!used[v] && v != p) {
		dist[v] = dist[u] + 1;
		dfs2(v, u, d, y);
	}
}
 
void solve() {
    int n;
    cin >> n;
 
    adj = vector<vector<int>>(n);
    par = vector<int>(n);
    dist = vector<int>(n);
    used = vector<bool>(n);
 
    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b, a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
 
    vector<array<int, 3>> seq;
 
    while (true) {
    	if (count(used.begin(), used.end(), false) == 0){
            break;
        }
    	vis.assign(n, false);
 
    	for (int i = 0; i < n; i++) {
    		if (vis[i] || used[i]) continue;
    		int d = 0, x = i;
 
    		dist[i] = 1;
    		dfs1(i, d, x);
 
    		dist[x] = 1;
    		d = 1;
    		int y = x;
    		dfs2(x, -1, d, y);

    		int cur = y;
    		while (cur != -1) {
    			used[cur] = true;
    			cur = par[cur];
    		}
 
    		if (x < y) swap(x, y);
 
 			seq.push_back({d, x, y});
    	}
    }

    sort(seq.begin(), seq.end(), greater<array<int, 3>>());
 
    for (auto i : seq) cout << i[0] << " " << i[1] + 1 << " " << i[2] + 1 << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}