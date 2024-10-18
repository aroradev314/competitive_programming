// CSES: Minimizing Coins

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	int dp[1000001];
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		dp[i] = INT_MAX;
		for (int j : coins) {
			if (i - j >= 0 && dp[i - j] != INT_MAX) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}
	}
	if (dp[x] == INT_MAX) {
		cout << -1;
	}
	else {
		cout << dp[x];
	}
}
	
	
	
	
	
