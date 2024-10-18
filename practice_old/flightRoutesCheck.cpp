// CSES: Flight Route Check
// Solved

#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;

void dfs(int node, vector<vector<int>> nextTo) {
	visited[node] = true;
	for (int i : nextTo[node]) {
		if (!visited[i]) {
			dfs(i, nextTo);
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1), reverseAdj(n + 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		reverseAdj[b].push_back(a);
	}
	visited = vector<bool>(n + 1);
	dfs(1, adj);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			cout << "1 " << i;
			return 0;
		}
	}
	visited = vector<bool>(n + 1);
	dfs(1, reverseAdj);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			cout << i << " 1";
			return 0;
		}
	}
	cout << "YES" << endl;
}
	
		
	
