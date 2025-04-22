#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == 0) {
    	cout << "1\n";
    	return;
    }

    vector<vector<int>> t, dp;
	t.push_back({-1, -1});
	dp.push_back({-1, -1});
    int cnt = 0;
    int ans = n + 1;
    // map<int, int> last;
    for (int i = 0; i < n; i++) {
    	int c = 0;
    	for (int j = 30; j >= 0; j--) {
    		int ibit = (a[i] >> j) & 1;
    		dp[c][ibit] = i;
    		if (t[c][ibit] == -1) {
    			t.push_back({-1, -1});
    			dp.push_back({-1, -1});
    			t[c][ibit] = ++cnt;
    		}
    		c = t[c][ibit];
    	}
    	// last[a[i]] = i;
    	// if (last.count(a[i] ^ k)) ans = min(ans, i - last[a[i] ^ k] + 1);
    	c = 0;
    	for (int j = 30; j >= 0; j--) {
    		int kbit = (k >> j) & 1;
    		int ibit = (a[i] >> j) & 1;
    		if (kbit) {
    			// so far we were equal to k, so we need to have
    			if (t[c][1 - ibit] != -1) {
    				if (j == 0) ans = min(ans, i - dp[c][1 - ibit] + 1);
    				c = t[c][1 - ibit];
    			}
    			else {
    				break;
    			}
    		}
    		else {
    			if (t[c][1 - ibit] != -1) ans = min(ans, i - dp[c][1 - ibit] + 1);

    			if (t[c][ibit] != -1) c = t[c][ibit];
    			else {
    				break;
    			}
    		}
    	}
    }

    cout << (ans == n + 1 ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    