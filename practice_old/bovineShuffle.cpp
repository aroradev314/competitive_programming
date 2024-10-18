#include <iostream>
#include <vector>
#include <queue>
using ll = long long;
using namespace std;


int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> adj(n), parent(n);
	queue<ll> never_visited;
	for (int i = 0; i < n; i++) {
		cin >> adj[i];
		adj[i]--;
		parent[adj[i]]++;
	}
	ll ans = n;
	for (int i = 0; i < n; i++) {
		if (parent[i] == 0) {
			ans--;
			never_visited.push(i);
		}
	}
	
	while (!never_visited.empty()) {
		ll cur = never_visited.front();
		never_visited.pop();
		
		if (--parent[adj[cur]] == 0) {
			never_visited.push(adj[cur]);
			ans--;
		}
	}
	cout << ans << endl;
	
	
}
	
