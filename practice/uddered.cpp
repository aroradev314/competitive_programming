#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
int cnt[30];
int which[30];
int adj[30][30];
int dp[1 << 21];

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < 26; i++) which[i] = -1;
    int c = 0;
    for (int i = 0; i < n; i++) {
    	int x = s[i] - 'a';
    	if (which[x] == -1) which[x] = c++;
    	cnt[which[x]]++;
    }

    for (int i = 1; i < n; i++) {
    	adj[which[s[i - 1] - 'a']][which[s[i] - 'a']]++;
    }

    dp[0] = 1;
    for (int i = 1; i < (1 << c); i++) {
    	dp[i] = n + 1;
    	for (int j = 0; j < c; j++) if ((1 << j) & i) {
    		int x = dp[i ^ (1 << j)];
    		int cur = 0;

    		for (int k = 0; k < c; k++) if ((1 << k) & i) cur += adj[k][j];

    		dp[i] = min(dp[i], x + cur);
    	}
    }

    cout << dp[(1 << c) - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    