#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<long long> tools(k);
	for (int i = 0; i < k; i++) {
		cin >> tools[i];
	}
	
	vector<int> dp(n + 1, 2e9);
	dp[1] = 0;
	
	for (int i = 1; i <= n; i++) {
		int current = i;
		for (long long a : tools) {
			if (a + (long long) current <= n) {
				dp[current + a] = min(dp[current + a], dp[current] + 1);
			}
			if ((long long) current * a <= n) {
				dp[current * a] = min(dp[current * a], dp[current] + 1);
			}
		}
	}
	if (dp[n] == 2e9) {
		cout << -1;
		return 0;
	}
	
	cout << dp[n];
}
			
		
	
	
	
