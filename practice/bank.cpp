#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 21;
int a[MAX_N], b[MAX_N];
int dp[1 << MAX_N];
int leftover[1 << MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < (1 << m); i++) dp[i] = -1;
	for (int i = 0; i < (1 << m); i++) leftover[i] = -1;

	dp[0] = 0;
	leftover[0] = 0;
	for (int i = 1; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			if ((i & (1 << j)) == 0) continue;
			int without = i ^ (1 << j);
			if (dp[without] == -1) continue;

			int new_amt = leftover[without] + b[j];
			int target = a[dp[without]];

			if (new_amt < target) {
				leftover[i] = new_amt;
				dp[i] = dp[without];
			}
			else if (new_amt == target) {
				leftover[i] = 0;
				dp[i] = dp[without] + 1;
			}
		}
		if (dp[i] == n) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    