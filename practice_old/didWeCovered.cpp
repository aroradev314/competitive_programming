#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k, m;

void test_case() {
	cin >> n >> k >> m;
	string s;
	cin >> s;
	vector<vector<int>> nxt(m, vector<int>(k));
	vector<int> seen(k, -1);
	
	for (int i = m - 1; i >= 0; i--) {
		seen[s[i] - 'a'] = i;
		for (int j = 0; j < k; j++) nxt[i][j] = seen[j];
	}
	
	string ans = "";
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < k; j++) {
			if (nxt[cur][j] == -1) {
				ans += (char) (j + 'a');
				while (ans.length() < n) ans += 'a';
				cout << "No\n" + ans + "\n";
				return;
			}
			mx = max(mx, nxt[cur][j]);
		}
		cur = mx;
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
