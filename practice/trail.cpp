#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];

    vector<ll> rows(n), cols(m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) rows[i] += grid[i][j];
    for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) cols[j] += grid[i][j];

    int r = 0, c = 0;
	for (int i = 0; i < n + m - 2; i++) {
		if (s[i] == 'D') {
			grid[r][c] = -rows[r];
			rows[r] += grid[r][c];
			cols[c] += grid[r][c];
			r++;
		}
		else {
			grid[r][c] = -cols[c];
			rows[r] += grid[r][c];
			cols[c] += grid[r][c];
			c++;
		}
	}
	grid[n - 1][m - 1] = -rows[n - 1];
	rows[n - 1] += grid[n - 1][m - 1];
	cols[m - 1] += grid[n - 1][m - 1];

	for (int i = 0; i < n; i++) assert(rows[i] == 0);
	for (int j = 0; j < m; j++) assert(cols[j] == 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << grid[i][j] << " ";
		cout << "\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    