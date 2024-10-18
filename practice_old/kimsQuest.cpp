#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

ll MOD = 998244353;
const int MAX_N = 2e5 + 10;
ll dp[MAX_N][2][2];
ll unfinished[2][2];

int add(ll a, ll b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	ll evens = 0, odds = 0;
	
	if (nums[0] % 2 == 0) evens++;
	else odds++;
	if (nums[1] % 2 == 0) evens++;
	else odds++;
	
	unfinished[nums[0] % 2][nums[1] % 2]++;
	
	int ans = 0;
	for (int i = 2; i < n; i++) {
		if (nums[i] % 2 == 0) {
			dp[i][0][0] += dp[i - 1][0][0];
			dp[i][1][0] += dp[i - 1][1][1];
			if (dp[i][0][0] >= MOD) dp[i][0][0] -= MOD;
			if (dp[i][1][0] >= MOD) dp[i][1][0] -= MOD;
			
			dp[i][0][0] += unfinished[0][0];
			dp[i][1][0] += unfinished[1][1];
			if (dp[i][0][0] >= MOD) dp[i][0][0] -= MOD;
			if (dp[i][1][0] >= MOD) dp[i][1][0] -= MOD;
		}
		else {
			dp[i][0][1] += dp[i - 1][1][0];
			dp[i][1][1] += dp[i - 1][0][1];
			if (dp[i][0][1] >= MOD) dp[i][0][1] -= MOD;
			if (dp[i][1][1] >= MOD) dp[i][1][1] -= MOD;
			
			dp[i][0][1] += unfinished[1][0];
			dp[i][1][1] += unfinished[0][1];
			if (dp[i][0][1] >= MOD) dp[i][0][1] -= MOD;
			if (dp[i][1][1] >= MOD) dp[i][1][1] -= MOD;
		}
		
		if (nums[i] % 2 == 0) {
			unfinished[1][0] += odds;
			unfinished[0][0] += evens;
			if (unfinished[1][0] >= MOD) unfinished[1][0] -= MOD;
			if (unfinished[0][0] >= MOD) unfinished[0][0] -= MOD;
			
			evens++;
		} 
		else {
			unfinished[0][1] += evens;
			unfinished[1][1] += odds;
			if (unfinished[0][1] >= MOD) unfinished[0][1] -= MOD;
			if (unfinished[1][1] >= MOD) unfinished[1][1] -= MOD;
			
			odds++;
		}
		
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans += dp[i][j][k];
				if (ans >= MOD) ans -= MOD;
			}
		}
		
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] += dp[i - 1][j][k];
				if (dp[i][j][k] >= MOD) dp[i][j][k] -= MOD;
			}
		}
	}
	
	cout << ans;
}

		
	
	
	
	
	

