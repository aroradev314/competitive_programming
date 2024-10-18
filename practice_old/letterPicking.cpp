#include <iostream>
#include <vector>
using namespace std;

void test_case() {
	string s;
	cin >> s;
	int n = s.length();
	
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	
	for (int len = 2; len <= n; len += 2) {
		for (int l = 0; l + len <= n; l++) {
			int r = l + len;
			dp[l][r] = -1;
			
			dp[l][r] = max(dp[l][r], min(dp[l + 1][r - 1], dp[l + 2][r]));
			dp[l][r] = max(dp[l][r], min(dp[l + 1][r - 1], dp[l][r - 2]));
		}
	}
	
	cout << dp[0][n] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

