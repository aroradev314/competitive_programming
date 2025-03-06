#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 998244353;
const int MAX_N = 2e5 + 10;
const int MAX_K = 650;

int dp[MAX_N]; // dp[i] = ways that we can get to i
int cur[MAX_N];// cur[i] = ways we can get to i for the last k

void solve() {
	int n, k;
	cin >> n >> k;

	cur[0] = 1;
	vector<int> mod(k + 1);
	for (int i = k; i <= k + MAX_K; i++) {
		vector<int> nmod;
		for (int j = 0; j <= n; j++) {
			dp[j] += mod[j % i];
			int bef = mod[j % i];
			mod[j % i] += cur[j % i];
			cur[j % i] = bef;
		}
		if (i <= n) {
			for (int j = 1; j <= n; j++) cout << dp[j] << " ";
			cout << endl;
		}
	}

	for (int i = 1; i <= n; i++) cout << dp[i] << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    