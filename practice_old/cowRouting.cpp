#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#define ll long long
using namespace std;

ll INF = LLONG_MAX;

int main() {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	ll a, b, n;
	cin >> a >> b >> n;
	
	vector<vector<pair<ll, ll>>> minCost(1001, vector<pair<ll, ll>>(1001, {INF, INF}));
	for (int i = 0; i < n; i++) {
		ll cost, cities;
		cin >> cost >> cities;
		vector<ll> route(cities);
		for (int j = 0; j < cities; j++) {
			cin >> route[j];
		}
		for (int start = 0; start < cities; start++) {
			for (int end = start + 1; end < cities; end++) {
				if (cost < minCost[route[start]][route[end]].first) {
					minCost[route[start]][route[end]] = {cost, end - start};
				}
				else if (cost == minCost[route[start]][route[end]].first && end - start < minCost[route[start]][route[end]].second) {
					minCost[route[start]][route[end]] = {cost, end - start};
				}
			}
		}
	}
	
	vector<pair<ll, ll>> distance(1001, {INF, INF});
	vector<bool> visited(1001);
	distance[a] = {0, 0};
	
	priority_queue<pair<ll, ll>> q;
	q.push({0, a});
	
	while (!q.empty()) {
		ll currentNode = q.top().second;
		q.pop();
		if (visited[currentNode]) {
			continue;
		}
		visited[currentNode] = true;
		
		for (int adj = 1; adj <= 1000; adj++) {
			ll cost = minCost[currentNode][adj].first, flights = minCost[currentNode][adj].second;
			if (cost != INF) {
				if (distance[currentNode].first + cost < distance[adj].first) {
					distance[adj] = {distance[currentNode].first + cost, distance[currentNode].second + flights};
					q.push({-distance[adj].first, adj});
				}
				else if (distance[currentNode].first + cost == distance[adj].first && distance[currentNode].second + flights < distance[adj].second) {
					distance[adj] = {distance[currentNode].first + cost, distance[currentNode].second + flights};
					q.push({-distance[adj].first, adj});
				}
			}
		}
	}
	
	if (!visited[b]) {
		cout << "-1 -1" << endl;
	}
	else {
		cout << distance[b].first << " " << distance[b].second << endl;
	}
}



		
		
		
	
	
	
	
	
	
	
	
	
	
	
