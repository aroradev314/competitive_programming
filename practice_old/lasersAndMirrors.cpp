// USACO 2016 December Contest, Gold  
// Problem 3. Lasers and Mirrors 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> points(n + 2);
	unordered_map<int, vector<int>> lines[2];
	for (int i = 0; i < n + 2; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
		lines[0][x].push_back(i);
		lines[1][y].push_back(i);
	}
	
	queue<pair<int, int>> q;
	vector<int> dist(n + 2, INT_MAX);
	dist[0] = 0;
	q.push({0, 1});
	q.push({0, 0});
	
	while (!q.empty()) {
		auto current = q.front();
		q.pop();
		
		int important = current.second ? points[current.first].second : points[current.first].first;
		
		for (int i : lines[current.second][important]) {
			if (dist[i] == INT_MAX) {
				dist[i] = dist[current.first] + 1;
				cout << i << endl
				q.push({i, 1 - current.second});
			}
		}
	}
	if (dist[1] == INT_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << dist[1] - 1 << endl;
	}
}
	
		
	
			
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
