#include <vector>
#include <iostream>
using namespace std;

const int MAX_N = 5005;
int dp[MAX_N][MAX_N];

int main() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) - 1;
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
			}
			dp[i][j] = max(dp[i][j], 0);
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}

			
			
