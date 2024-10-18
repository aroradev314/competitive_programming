// USACO Gold 2018 December
// P3
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	
	vector<int> skills(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> skills[i];
	}
	
	vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(k + 1));
	
	for (int i = 1; i <= n; i++) {
		int maxBefore = 0;
		for (int j = 1; j <= k; j++) {
			maxBefore = max(maxBefore, dp[i - 1][j].first);
		}
		dp[i][1] = {maxBefore + skills[i], skills[i]};
		for (int j = 2; j <= k; j++) {
			int maxElement = max(skills[i], dp[i - 1][j - 1].second);
			int total = dp[i - 1][j - 1].first - (dp[i - 1][j - 1].second * min(j - 1, i - 1));
			dp[i][j] = {total + maxElement * min(j, i), maxElement};
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans = max(ans, dp[n][i].first);
	}
	cout << ans << endl;
}
	
