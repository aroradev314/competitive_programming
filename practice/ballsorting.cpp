#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 510;
int dp[MAX_N][MAX_N][2];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans(n + 10, INT_MAX);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	for (int i = 1; i <= n; i++) { // index
		if (i > 1) dp[i][1][1] = 1;
		else dp[i][0][0] = 1;

		for (int j = 1; j < i; j++) { // last element
			if (a[j] > a[i]) continue;
			for (int k = 0; k <= n; k++) { // gap
				for (int ind : {0, 1}) {
					if (dp[j][k][ind] == -1) continue;

					int upd = dp[j][k][ind] + 1;
					int new_gap = k;
					if (j != i - 1) new_gap++;
					dp[i][new_gap][ind] = max(dp[i][new_gap][ind], upd);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= n; k++) {
			for (int ind : {0, 1}) {
				if (dp[i][k][ind] == -1) continue;
				int gap = (i == n ? k : k + 1);
				ans[gap] = min(ans[gap], n - dp[i][k][ind]);
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= i; j++) cout << dp[i][j][0] << " " << dp[i][j][1] << "     ";
	// 	cout << endl;
	// }


	for (int i = 1; i <= n; i++) ans[i] = min(ans[i], ans[i - 1]);
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    