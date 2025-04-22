#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MX_N = 1e5 + 10;
const int MX_A = 520;

int a[MX_N];
int dp[MX_A];

void ck_min(int& x, int y) {
	if (x == -1 || y < x) x = y;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 1; i < MX_A; i++) dp[i] = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MX_A; j++) if (dp[j] != -1 && dp[j] < a[i]) {
			// we can add on to this prefix
			ck_min(dp[a[i] ^ j], a[i]);
		}
	}

	vector<int> ans;
	for (int i = 0; i < MX_A; i++) if (dp[i] != -1) ans.push_back(i);
	cout << sz(ans) << "\n";
	for (int i : ans) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    