// USACO 2021 Jan Silver P2
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

	vector<vector<int>> pos(26);
	vector<int> minSinceSeen(26, -1), dp(n + 1);
	vector<bool> usedPrev(n + 1, true);
	
	for (int i = 1; i <= n; i++) {
		int current = s[i - 1] - 'a';
		dp[i] = dp[i - 1];
		if (minSinceSeen[current] < current) {
			dp[i]++;
			usedPrev[i] = false;
		}
		minSinceSeen[current] = current;
		for (int c = 0; c < 26; c++) {
			minSinceSeen[c] = min(minSinceSeen[c], current);
		}
		pos[current].push_back(i);
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int ans = dp[l - 1] + (dp[n] - dp[r]);
		for (int c = 0; c < 26; c++) {
			auto first = upper_bound(pos[c].begin(), pos[c].end(), r);
			if (first != pos[c].end() && usedPrev[*first]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}

				
	
		
