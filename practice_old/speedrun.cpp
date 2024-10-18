#include <vector>
#include <queue>
#include <iostream>
typedef long long ll;
using namespace std;	

void update(ll& cur_a, ll new_a, ll& cur_b, ll new_b) {
	if (new_a > cur_a) {
		cur_a = new_a;
		cur_b = new_b;
	}
}

void test_case() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> h(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	
	vector<vector<int>> adj(n + 1), reverse_adj(n + 1);
	vector<int> in(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		reverse_adj[b].push_back(a);
		in[b]++;
	}
	
	vector<int> topo;
	queue<int> cur;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) cur.push(i);
	}
	
	while (!cur.empty()) {
		int c = cur.front(); cur.pop();
		
		for (int i : adj[c]) {
			in[i]--;
			if (in[i] == 0) cur.push(i);
		}
		topo.push_back(c);
	}
	
	vector<ll> dp(n + 1), first(n + 1);
	ll ans = 0;
	for (int i : topo) {
		if (reverse_adj[i].size() == 0) {
			first[i] = h[i];
			continue;
		}
		
		ll time = 0, first_val = 0;
		for (int j : reverse_adj[i]) {
			ll pre = (first[j] + dp[j]) % k;
			if (h[i] >= pre) {
				update(time, dp[j] + (h[i] - pre), first_val, first[j]);
			}
			else {
				update(time, dp[j] + (k - pre) + h[i], first_val, first[j]);
			}
		}
		dp[i] = time;
		first[i] = first_val;
		ans = max(ans, dp[i]);
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
