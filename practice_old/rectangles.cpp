#include <vector>
#include <iostream>
#define ll long long
using namespace std;

constexpr int MAX_N = 1005;
ll nums[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N];

void test_case() {
	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> nums[i][j];
		}
	}
	ll total = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = 1;
			if (nums[i][j] == nums[i - 1][j]) {
				dp[i][j] += dp[i - 1][j];
			}
			if (nums[i][j] == nums[i][j - 1]) {
				dp[i][j] += dp[i][j - 1];
			}
			if (nums[i][j] == nums[i - 1][j - 1]) {
				dp[i][j] -= dp[i - 1][j - 1];
			}
			total += dp[i][j];
		}
	}
	cout << total << endl;
}
			
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

