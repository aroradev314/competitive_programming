// Gold 2019 US Open
// P1
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	
	vector<int> groups(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> groups[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	
	int totalSize = 0;
	int maxNet = 0;
	for (int i = 1; i <= n; i++) {
		maxNet = max(maxNet, groups[i]);
		dp[i][0] = maxNet * i;
		
		for (int j = 1; j <= k; j++) {
			dp[i][j] = INT_MAX;
			int netSize = groups[i];
			for (int c = i - 1; c >= 0; c--) {
				dp[i][j] = min(dp[i][j], dp[c][j - 1] + netSize * (i - c));
				netSize = max(netSize, groups[c]);
			}
		}
		totalSize += groups[i];
	}
	cout << dp[n][k] - totalSize << endl;
}
	
					
	
	
