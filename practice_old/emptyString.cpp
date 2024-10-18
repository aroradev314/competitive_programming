#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b) {
	return int((1LL * a * b) % MOD);
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	
	vector<vector<int>> choose(n + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; i++) {
		choose[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		dp[i + 1][i] = 1;
	}
	for (int len = 2; len <= n; len += 2) {
		for (int i = 0; i + len <= n; i++) {
			int j = i + len - 1;
			for (int k = i + 1; k <= j; k++) {
				if (s[i] == s[k]) {
					int current = mul(mul(dp[i + 1][k - 1], dp[k + 1][j]), choose[(j - i + 1) / 2][(k - i + 1) / 2]);
					dp[i][j] = add(dp[i][j], current);
				}
			}
		}
	}
	
	cout << dp[0][n - 1] << "\n";
}

				
	
	
			
	
