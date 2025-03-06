#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    string a, b, c;
 	cin >> a >> b >> c;

 	a = " " + a, b = " " + b, c = " " + c;
 	int n = a.length() - 1, m = b.length() - 1;
 	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

 	for (int i = 0; i <= n; i++) {
 		for (int j = 0; j <= m; j++) {
 			if (i == 0 && j == 0) continue;
 			else if (i > 0 && j == 0) {
 				dp[i][j] = dp[i - 1][j] + (a[i] == c[i] ? 0 : 1);
 			}
 			else if (i == 0 && j > 0) dp[i][j] = dp[i][j - 1] + (b[j] == c[j] ? 0 : 1);
 			else {
 				dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
 				if (a[i] == c[i + j]) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
 				if (b[j] == c[i + j]) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
 			}
 			// cout << i << " " << j << " " << dp[i][j] << "\n";
 		}
 	}
 	cout << dp[n][m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    