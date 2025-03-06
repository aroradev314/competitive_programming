#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    vector<int> ones(n);
    for (int i = 0; i < n; i++) {
    	int p = n - 1;
    	while (p > 0 && a[i][p] == 1) p--;
    	ones[i] = n - 1 - p;
    }

    sort(ones.begin(), ones.end());
    vector<int> dp(n); // dp[i] is the longest mex subsequence that ends at i

    int ans = 0;
    for (int i = 0; i < n; i++) {
    	dp[i] = 1;
    	for (int j = 0; j < i; j++) {
    		if (ones[i] >= dp[j]) dp[i] = max(dp[i], dp[j] + 1);
    	}
    	ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    