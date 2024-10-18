// CSES: Dice Combinations

#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long dp[1000001];
	
	int n;
	cin >> n;
	int MOD = 1e9 + 7;
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = i - 1; j >= 0 && j >= i - 6; j--) {
			dp[i] += dp[j];
			dp[i] %= MOD;
		}
	}
	cout << dp[n] << endl;
}
	
	
	
