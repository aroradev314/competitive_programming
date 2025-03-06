#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e6;
const int MOD = 998244353;
int dp[MAX_N + 10], divisors[MAX_N + 10];
int prime[MAX_N + 10];
vector<int> factors[MAX_N + 10];

void add(int& a, int b) {
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
}

void solve() {
	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i] == 0) {
			for (int j = i; j <= MAX_N; j += i) prime[j] = i;
		}
	}

    for (int i = 2; i <= MAX_N; i++) {
    	factors[i].push_back(prime[i]);
    	for (int j : factors[i / prime[i]]) factors[i].push_back(j);
    	factors[i].erase(unique(factors[i].begin(), factors[i].end()), factors[i].end());
    }

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < (1 << sz(factors[a[i]])); j++) {
			int par = __builtin_popcount(j) % 2;
			int prod = 1;
			for (int k = 0; k < sz(factors[a[i]]); k++) if ((1 << k) & j) prod *= factors[a[i]][k];
			if (par) add(dp[i], divisors[prod]);
			else add(dp[i], -divisors[prod]);
		}
		for (int j = 1; j < (1 << sz(factors[a[i]])); j++) {
			int prod = 1;
			for (int k = 0; k < sz(factors[a[i]]); k++) if ((1 << k) & j) prod *= factors[a[i]][k];
			// cout << a[i] << " " << prod << endl;
			add(divisors[prod], dp[i]);
		}
	}
	cout << dp[n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    