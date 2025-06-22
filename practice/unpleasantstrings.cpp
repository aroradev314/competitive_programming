#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	s = " " + s;
	vector<vector<int>> nxt(n + 1, vector<int>(k));
	vector<vector<int>> len(n + 1, vector<int>(k));
	vector<int> dp(n + 1, 1e9);

	for (int i = 0; i < k; i++) {
		nxt[n][i] = -1;
		len[n][i] = 1; // longest length starting with the ith character
	}
	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		nxt[i] = nxt[i + 1];
		nxt[i][s[i + 1] - 'a'] = i + 1;
		len[i] = len[i + 1];
		len[i][s[i + 1] - 'a'] = 1 + dp[i + 1];
		for (int j = 0; j < k; j++) dp[i] = min(dp[i], len[i][j]);
	}
	
	int q;
	cin >> q;
	while (q--) {
		string x;
		cin >> x;
		int cur = 0;
		for (int i = 0; i < (int) x.length() && cur >= 0; i++) {
			cur = nxt[cur][x[i] - 'a'];
		}
		if (cur == -1) cout << "0\n";
		else cout << dp[cur] << "\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    