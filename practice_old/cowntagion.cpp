// USACO 2020 Silver P1

#include <vector>
#include <iostream>
using namespace std;

long long totalMoves = 0;
vector<vector<int>> adj;

void dfs(int node, int parent) {
	int totalDouble = 0;
	int required = adj[node].size();
	if (parent != -1) {
		required--;
	}
	for (int i = 1; i <= required; i *= 2) {
		totalDouble++;
	}
	totalMoves += required + totalDouble;
	
	for (int i : adj[node]) {
		if (i != parent) {
			dfs(i, node);
		}
	}	
}

int main() {
	int n;
	cin >> n;
		
	adj.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	cout << totalMoves << endl;
}

	
	
	
	
	
