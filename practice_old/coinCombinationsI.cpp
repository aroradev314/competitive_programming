// CSES: Coin Combinations I

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define ll long long
using namespace std;

int main() {
	ll dp[(int) 1e6 + 1];
	int MOD = 1e9 + 7;
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		dp[i] = 0;
		for (int j : coins) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[x] << endl;
}
	
	
	
	
	

