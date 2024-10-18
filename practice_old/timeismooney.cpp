// USACO 2020 January, Gold
// P1
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	
	vector<int> value(n);
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	
	vector<vector<int>> in(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		in[b].push_back(a);
	}
	
	vector<vector<ll>> dp(510, vector<ll>(n, -INT_MAX));
	dp[0][0] = 0;
	ll ans = 0;
	for (int i = 1; i < 510; i++) {
		for (int city = 0; city < n; city++) {
			for (int lastCity : in[city]) {
				if (dp[i - 1][lastCity] != -INT_MAX) {
					dp[i][city] = max(dp[i][city], dp[i - 1][lastCity] + value[city]);
				}
			}
			if (city == 0 && dp[i][city] != -INT_MAX) {
				ans = max(ans, dp[i][city] - c * i * i);
			}
		}
	}
	cout << ans << endl;
}
		
			
	
	
	
		
