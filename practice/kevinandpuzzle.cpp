#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 998244353;
const int MAX_N = 200200;

int dp[MAX_N][2][2];
int a[MAX_N];

int add(int x, int y) {
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 3; i <= n + 2; i++) cin >> a[i];

    dp[1][0][0] = 1;
	dp[2][0][0] = 1;

	for (int i = 3; i <= n + 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = 0;

	for (int i = 3; i <= n + 2; i++) {
		dp[i][1][0] = add(dp[i - 1][0][0], dp[i - 1][0][1]);
		if (a[i] == a[i - 2] + 1 && i != 3) dp[i][0][1] = add(dp[i - 2][0][1], dp[i - 2][0][0]);
		if (a[i] == a[i - 1]) dp[i][0][0] = add(dp[i - 1][0][0], dp[i - 1][0][1]);
	}

	int ans = add(add(dp[n + 2][0][0], dp[n + 2][0][1]), dp[n + 2][1][0]);
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    