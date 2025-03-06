#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MX_N = 2020;
int dp1[MX_N][MX_N];
int dp2[MX_N][MX_N];
int p[MX_N], c[MX_N], x[MX_N];

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) cin >> p[i] >> c[i] >> x[i];

    vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int u, int v) {
		return x[u] > x[v];
	});

	for (int i = 0; i < n; i++) {
		int pos = ord[i];
		for (int j = 1; j <= a; j++) {
			dp1[i + 1][j] = dp1[i][j];
			if (j >= c[pos]) 
				dp1[i + 1][j] = max(dp1[i + 1][j], p[pos] + dp1[i][j - c[pos]]);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		int pos = ord[i];
		for (int j = 1; j <= b; j++) {
			dp2[i + 1][j] = dp2[i + 2][j];
			if (j >= x[pos] * c[pos]) 
				dp2[i + 1][j] = max(dp2[i + 1][j], p[pos] + dp2[i + 2][j - x[pos] * c[pos]]);
		}
	}

	// dp1[i] is buying with moonies from a prefix
	// dp2[i] is buying with cones from a suffix

	int ans = max(dp1[n][a], dp2[1][b]);
	for (int i = 1; i <= n; i++) {
		int pos = ord[i - 1];

		// if this is the last one that we spend any moonies on and we buy this one
		ans = max(ans, dp1[i][a] + dp2[i + 1][b]);

		for (int j = 0; j <= a; j++) {
			if (j * x[pos] + b >= c[pos] * x[pos]) ans = max(ans, p[pos] + dp1[i - 1][a - j] + dp2[i + 1][b - x[pos] * (c[pos] - j)]);
		}
	}

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    