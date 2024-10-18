//  USACO 2015 US Open, Silver 
// P3
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(vector<vector<ll>>& adj, vector<vector<ll>>& distance, int start, int e) {
	queue<int> q;
	q.push(start);
	distance[start][start] = 0;
	
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (int i : adj[node]) {
			if (distance[start][i] == -1) {
				distance[start][i] = distance[start][node] + e;
				q.push(i);
			}
		}
	}
}

			

int main() {
	freopen("buffet.in", "r", stdin);
	freopen("buffet.out", "w", stdout);
	int n, e;
	cin >> n >> e;
	
	vector<pair<ll, ll>> quality(n);
	vector<vector<ll>> adj(n);
	for (int i = 0, d; i < n; i++) {
		ll c;
		cin >> c;
		quality[i] = {c, i};
		cin >> d;
		for (int j = 0; j < d; j++) {
			int a;
			cin >> a; a--;
			adj[i].push_back(a);	
		}
	}
	
	vector<vector<ll>> distance(n, vector<ll>(n, -1));
	for (int i = 0; i < n; i++) {
		bfs(adj, distance, i, e);
	}
	
	vector<ll> dp(n);
	ll ans = 0;
	sort(quality.begin(), quality.end());
	for (int i = 0; i < n; i++) {
		dp[quality[i].second] = quality[i].first; 
		for (int j = 0; j < i; j++) {
			if (distance[quality[i].second][quality[j].second] != -1) {
				dp[quality[i].second] = max(dp[quality[i].second], dp[quality[j].second] + quality[i].first - distance[quality[i].second][quality[j].second]);
			}
		}
		ans = max(ans, dp[quality[i].second]);
	}
	cout << ans << endl;
}
		 
	
	
	
