#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

int on(int x, int b) {
	return ((x & (1 << b)) ? 1 : 0);
}

void solve() {
    // store a trie for each query
    // each node of the trie should hold which queries branch down from here
    // we iterate through w from right to left
    // then we need to find what nodes when xored with the suffix of w so far would be less than this w_i

    int n, q;
    cin >> n >> q;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<vector<int>> trie = {{-1, -1}};
	vector<vector<set<int>>> s = {{{}, {}}};

	int cur = 1;
	vector<int> queries(q);
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		queries[i] = x;

		int u = 0;
		for (int j = 29; j >= 0; j--) {
			int b = on(x, j);
			if (trie[u][b] == -1) {
				trie[u][b] = cur++;
				trie.push_back({-1, -1});
				s.push_back({{}, {}});
			}
			s[u][b].insert(i);
			u = trie[u][b];
		}
	}

	int suff = 0;
	vector<int> ans(q, n);
	vector<bool> done(q);
	for (int i = n - 1; i >= 0; i--) {
		int u = 0;
		for (int j = 29; j >= 0 && u >= 0; j--) {
			int b = on(w[i], j);
			int c = on(suff, j);
			if (b == 1) {
				vector<int> era;
				for (int k : s[u][c]) {
					if (!done[k]) {
						ans[k] = min(ans[k], n - 1 - i);
						done[k] = true;
					}
					else era.push_back(k);
				}
				for (int k : era) s[u][c].erase(k);
			}
			u = trie[u][b ^ c];
		}
		suff ^= w[i];
	}

	for (int i : ans) cout << i << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    