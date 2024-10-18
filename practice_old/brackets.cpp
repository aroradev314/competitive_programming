#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<ll> v(n), b(n);
	for (int i = 0; i < n; i++) {
	    cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
	    cin >> b[i];
	}
	
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
	
	for (int len = 2; len <= n; len++) {
	    for (int i = 0; i + len <= n; i++) {
	        int j = i + len - 1;
	        for (int mid = i; mid < j; mid++) {
				dp[i][j] = max(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
			}
			if (b[i] + x == b[j]) {
				dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + v[i] + v[j]);
			}
	    }
	}
	cout << dp[0][n - 1] << "\n";
	
	return 0;
}
