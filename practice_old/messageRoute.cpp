// CSES: Message Route

#include <vector>
#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

int main() {
	int n, m; 
	cin >> n >> m;
	adj.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> distance(n + 1, INT_MAX), parent(n + 1);
	distance[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int t : adj[x]) {
			if (distance[t] == INT_MAX) {
				distance[t] = distance[x] + 1;
				parent[t] = x;
				q.push(t);
			}
		}
	}
	if (distance[n] == INT_MAX) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		int current = n;
		vector<int> path;
		while (current != 1) {
			path.push_back(current);
			current = parent[current];
		}
		path.push_back(1);
		reverse(path.begin(), path.end());
		cout << path.size() << endl;
		for (int i : path) {
			cout << i << " ";
		}
		cout << endl;
	}
}
			
	
	
	
