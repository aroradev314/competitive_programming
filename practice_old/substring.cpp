#include <vector>
#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

vector<int> order;

bool infinite = false;

void topo(int node, vector<vector<int>>& adj, vector<bool>& visited, set<int> curVisited) {
	visited[node] = true;
	curVisited.insert(node);
	for (int i : adj[node]) {
		if (curVisited.count(i)) {
			infinite = true;
			return;
		}
		if (!visited[i]) {
			topo(i, adj, visited, curVisited);
		}
	}
	order.push_back(node);
}
	
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	vector<vector<int>> adj(n);
	vector<set<int>> rAdj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		if (a == b) {
			cout << -1 << endl;
			return 0;
		}
		adj[a].push_back(b);
		rAdj[b].insert(a);
	}
	
	vector<bool> visited(n);
	set<int> curVisited;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			curVisited.clear();
			topo(i, adj, visited, curVisited);
		}
	}
	if (infinite) {
		cout << -1;
		return 0;
	}
	reverse(order.begin(), order.end());
	
	vector<vector<int>> dp(n, vector<int>(26));
	int ans = 0;
	for (int node : order) {
		for (int before : rAdj[node]) {
			for (int i = 0; i < 26; i++) {
				dp[node][i] = max(dp[node][i], dp[before][i]);
				ans = max(ans, dp[node][i]);
			}
		}
		dp[node][s[node] - 'a']++;
		ans = max(ans, dp[node][s[node] - 'a']);
	}
	cout << ans << endl;
}

	
	
