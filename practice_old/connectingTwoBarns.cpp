#include <vector>
#include <iostream>
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

void dfs(ll node, vector<ll>& comp, vector<bool>& visited, vector<vector<ll>>& adj) {
	comp.push_back(node);
	visited[node] = true;
	
	for (int i : adj[node]) {
		if (!visited[i]) {
			dfs(i, comp, visited, adj);
		}
	}
}

void test_case() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<ll> start, last;
	vector<bool> visited(n + 1);
	dfs(1, start, visited, adj);
	
	fill(visited.begin(), visited.end(), false);
	dfs(n, last, visited, adj);
	
	sort(start.begin(), start.end());
	sort(last.begin(), last.end());
	vector<ll> startDist(n + 1, 2e15), lastDist(n + 1, 2e15);
	
	for (int i = 1; i <= n; i++) {
		auto sdist = lower_bound(start.begin(), start.end(), i);
		if (sdist != start.end()) {
			startDist[i] = (*sdist - i) * (*sdist - i);
		}
		if (sdist != start.begin()) {
			sdist--;
			startDist[i] = min(startDist[i], (*sdist - i) * (*sdist - i));
		}
		
		auto edist = lower_bound(last.begin(), last.end(), i);
		if (edist != last.end()) {
			lastDist[i] = (*edist - i) * (*edist - i);
		}
		if (edist != last.begin()) {
			edist--;
			lastDist[i] = (*edist - i) * (*edist - i);
		}
	}
	
	
	
	vector<ll> comp;
	fill(visited.begin(), visited.end(), false);
	ll ans = 2e15;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		
		dfs(i, comp, visited, adj);
		ll minStart = 2e15, minLast = 2e15;
		for (int j : comp) {
			minStart = min(minStart, startDist[j]);
			minLast = min(minLast, lastDist[j]);
		}
		ans = min(ans, minStart + minLast);
		
		comp.resize(0);
	}
	
	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

