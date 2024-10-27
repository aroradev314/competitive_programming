#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e6 + 10;
const int MAX_M = 5010;
int dp[MAX_M], diff[MAX_M];
int a[MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	n++;
	a[n] = 0;

	// dp[i] i is max for spending i coins on intelligence
	int points = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			points++;
			dp[0] += diff[0];
			for (int j = 1; j <= m; j++) {
				diff[j] += diff[j - 1];
				dp[j] += diff[j];
			}
			for (int j = m; j >= 1; j--) {
				dp[j] = max(dp[j], dp[j - 1]);
				diff[j] = 0;
			}
			diff[0] = 0;
		}
		else if (a[i] > 0) {
			int mn = a[i], mx = points + 1;
			if (mn <= points) {
				diff[mn]++;
				diff[mx]--;
			}
		}
		else {
			a[i] = abs(a[i]);
			int mn = 0, mx = points - a[i] + 1;
			if (mn < mx) {
				diff[mn]++;
				diff[mx]--;
			}
		}
	}

	int ans = dp[0];
	for (int i = 1; i <= m; i++) ans = max(ans, dp[i]);
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    