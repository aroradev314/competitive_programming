#include <vector>
#include <iostream>
using namespace std;

const int INF = 2e9;
int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	
	vector<pair<int, int>> dp(1 << n);
	dp[0] = {1, 0};
	
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = {INF, INF};
		for (int j = 0; j < n; j++) {
			if ((1 << j) & i) {
				auto before = dp[i ^ (1 << j)];
				pair<int, int> x;
				if (w[j] + before.second > m) {
					x = {before.first + 1, min(before.second, w[j])};
				}
				else {
					x = {before.first, before.second + w[j]};
				}
				dp[i] = min(dp[i], x);
			}
		}
	}
	cout << dp[(1 << n) - 1].first;
}

		
	
