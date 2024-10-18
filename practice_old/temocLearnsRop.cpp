#include <vector>
#include <iostream>
#define ll long long
using namespace std;

vector<int> a, current;
vector<vector<int>> adj;
vector<bool> visited;

const int MOD = 1e9 + 7;

void dfs(int node) {
	current.push_back(node);
	visited[node] = true;
	
	for (int i : adj[node]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}	

ll mul(ll x, ll y) {
	x = (x * y) % MOD;
	return x;
}

ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

ll binexp(long long x, long long y) {
	if (y == 0) {
		return 1LL;
	}
	
	ll ans = binexp(x, y / 2);
	ans = mul(ans, ans);
	
	if (y % 2 == 1) {
		ans = mul(ans, x);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	
	a.resize(n + 1);
	adj.resize(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	long long total = 0;
	visited.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		current.resize(0);
		dfs(i);
		
		vector<int> values;
		for (int j : current) {
			values.push_back(a[j]);
		}
		
		sort(current.begin(), current.end());
		sort(values.begin(), values.end());
				
		for (int j = 0; j < (int) current.size(); j++) {
			total = add(total, mul(values[j], binexp(n - current[j] + 1, n - current[j] + 1)));
		}
	}
	
	cout << total << "\n";
}

	
	
	
	
		
	
	
