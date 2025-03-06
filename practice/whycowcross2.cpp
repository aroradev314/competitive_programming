#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;
	
const int MAX_N = 1010;
int a[MAX_N], b[MAX_N];
int wa[MAX_N], wb[MAX_N];
int dp[MAX_N][MAX_N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1; i <= n; i++) wa[a[i]] = i;
	for (int i = 1; i <= n; i++) wb[b[i]] = i;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (abs(a[i] - b[j]) <= 4) dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int t = 1;
    while (t--) solve();
}
    