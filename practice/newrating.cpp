#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 3e5 + 10;
int a[MAX_N];
int dp[MAX_N][3];

int calc(int cur, int rating) {
	if (cur < rating) return cur + 1;
	else if (cur > rating) return cur - 1;
	else return cur;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
    	dp[i][0] = calc(dp[i - 1][0], a[i]);
    	dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
    	if (i > 1) dp[i][2] = max(calc(dp[i - 1][1], a[i]), calc(dp[i - 1][2], a[i]));
    	// cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << max(dp[n][1], dp[n][2]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    