// CSES: Removing Digits

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	ll dp[(int)1e6 + 1];
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int current = i;
		dp[i] = INT_MAX;
		while (current != 0) {
			dp[i] = min(dp[i], dp[i - (current % 10)] + 1);
			current /= 10;
		}
	}
	cout << dp[n] << endl;
}
	
	
	
	



