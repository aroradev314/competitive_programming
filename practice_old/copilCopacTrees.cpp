// Codeforces Round 875
// C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<int>& dp, vector<int>& id) {
	for (auto i : adj[node]) {
		int v = i.first;
		int index = i.second;
		if (v != parent) {
			id[v] = index;
			if (index >= id[node]) {
				dp[v] = dp[node];
			}
			else {
				dp[v] = dp[node] + 1;
			}
			dfs(v, node, adj, dp, id);
		}
	}
}
			
void test_case() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> adj(n + 1);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(make_pair(b, i));
		adj[b].push_back(make_pair(a, i));
	}
	
	vector<int> dp(n + 1), id(n + 1);
	
	dp[1] = 1;
	id[1] = 0;
	
	dfs(1, -1, adj, dp, id);
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

