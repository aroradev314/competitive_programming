#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void topo(int node, vector<vector<int>>& adj, vector<int>& nodes, vector<bool>& visited) {
	visited[node] = true;
	for (int b : adj[node]) {
		if (!visited[b]) {
			topo(b, adj, nodes, visited);
		}
	}
	nodes.push_back(node);
}
	
int main() {
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	
	vector<int> early(n);
	for (int i = 0; i < n; i++) {
		cin >> early[i];
	}
	
	vector<vector<int>> adj(n);
	vector<vector<pair<int, int>>> reverseAdj(n);
	for (int i = 0; i < c; i++) {
		int a, b, x;
		cin >> a >> b >> x; a--; b--;
		adj[a].push_back(b);
		reverseAdj[b].push_back({a, x});
	}
	
	vector<bool> visited(n);
	vector<int> nodes;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			topo(i, adj, nodes, visited);
		}
	}
	reverse(nodes.begin(), nodes.end());
	
	for (int node : nodes) {
		for (auto& [before, x] : reverseAdj[node]) {
			early[node] = max(early[node], early[before] + x);
		}
	}
	for (int i : early) {
		cout << i << endl;
	}
}

			
		
		
	
	
	
	
	
	

