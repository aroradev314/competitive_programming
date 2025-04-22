#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 10;
int fact[MAX_N];
int inv_fact[MAX_N];

int add(ll a, ll b) {
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
	return a;
}

int mul(ll a, ll b) {
	return (int) ((a * 1LL * b) % MOD);
}

int binexp(ll a, ll b) {
	if (b == 0) return 1;
	int ans = binexp(a, b / 2);
	ans = mul(ans, ans);
	if (b % 2) ans = mul(ans, a);
	return ans;
}

int inv(ll a) {
	return binexp(a, MOD - 2);
}

int choose(int a, int b) {
	if (a < b) return 0;
	return mul(fact[a], mul(inv_fact[b], inv_fact[a - b]));
}

void solve() {
	fact[0] = 1;
	inv_fact[0] = inv(fact[0]);
	for (int i = 1; i < MAX_N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv_fact[i] = inv(fact[i]);
	}

	ll k, l;
	int n;
	cin >> k >> n >> l;
	string s;
	cin >> s;

	int cur = 0;
	ll ans = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'O') cur++;
		else {
			ans = mul(ans, choose(cur, k));
			cur -= k;
		}
	}

	ans = binexp(ans, l);
	cout << ans;
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    solve();
}
    