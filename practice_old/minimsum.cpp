// Source: https://usaco.guide/general/io

#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

const int MAX_N = 2e5;
const int MAX_K = 10;
ll dp[MAX_N + 10][MAX_K + 2];

void test_case() {
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		for (int u = 0; u <= k; u++) {
			dp[i][u] = dp[i - 1][u] + arr[i];
			ll mn = arr[i];
			for (int b = 1; b <= min(i - 1, u); b++) {
				mn = min(mn, arr[i - b]);
				ll x = mn * (b + 1) + dp[i - b - 1][u - b];
				dp[i][u] = min(dp[i][u], x);
			}
		}
	}
	
	cout << dp[n][k] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) test_case();
}
