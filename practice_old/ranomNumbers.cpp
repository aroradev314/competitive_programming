// Educational Codeforces Round 150
// C

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits.h>
using namespace std;

int dp[(int)2e5 + 1][5][2];
int val[] = {1, 10, 100, 1000, 10000};

void test_case() {
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k : {0, 1}) {
				dp[i][j][k] = INT_MIN;
			}
		}
	}
	
	dp[0][0][0] = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 5; j++) {
			for (int k : {0, 1}) {
				if (dp[i][j][k] != INT_MIN) {
					int current = s[i] - 'A';
					for (int rep = 0; rep < 5; rep++) {
						int newK = k + (int)(rep != current);
						if (newK >= 2) continue;
						int last = dp[i][j][k];
						int newJ = j;
						if (rep < j) {
							last -= val[rep];
						}
						else {
							last += val[rep];
							newJ = rep;
						}
						dp[i + 1][newJ][newK] = max(dp[i + 1][newJ][newK], last);
					}
				}
			}
		}
	}
	
	int ans = INT_MIN;
	
	for (int i = 0; i < 5; i++) {
		ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}


