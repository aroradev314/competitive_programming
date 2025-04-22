#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 10;

int add(ll a, ll b) {
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
	return a;
}

int mul(ll a, ll b) {
	return (int) ((a * 1LL * b) % MOD);
}

void solve() {
	int n, d;
	cin >> n >> d;
	int a, b;
	cin >> a >> b;

	vector<int> m(n);
	for (int i = 0; i < n; i++) cin >> m[i];
	sort(m.begin(), m.end());

	 	
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    solve();
}