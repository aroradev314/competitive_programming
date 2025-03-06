#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1010;
int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int chain[MAX_N][MAX_N];

void solve() {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> grid[i][j];

    ll ans = 0;
    for (int i = 1; i <= r; i++) {
    	stack<int> s;
    	int len = 0;
    	for (int j = 1; j <= c; j++) {
    		chain[i][j] = 1;
    		if (grid[i][j] == grid[i - 1][j]) chain[i][j] += chain[i - 1][j];
    		if (grid[i][j] == grid[i][j - 1]) {
    			len++;
    			while (sz(s) && chain[i][s.top()] >= chain[i][j]) s.pop();
    			if (sz(s)) {
    				dp[i][j] = (j - s.top()) * chain[i][j] + dp[i][s.top()];
    			}
    			else dp[i][j] = len * chain[i][j];
    		}
    		else {
    			while (sz(s)) s.pop();
    			len = 1;
    			dp[i][j] = chain[i][j];
    		}
    		s.push(j);
    		ans += dp[i][j];
    	}
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
    