#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const ll MOD = (1LL << 61) - 1;
const int MAX_N = 2e5 + 10;
const int B = 1558;
ll hsh[MAX_N];
ll p[MAX_N];

__int128 mul(ll a, ll b) { return (__int128)a * b; }
ll mod_mul(ll a, ll b) { return mul(a, b) % MOD; }
ll add(ll a, ll b) {
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
	return a;
}
ll sub(ll a, ll b) {
	return add(a, -b);
}

string n, h;

void solve() {
	cin >> n >> h;
	if (n.length() > h.length()) {
		cout << 0;
		return;
	}

	p[0] = 1;
	for (int i = 1; i < MAX_N; i++) p[i] = mod_mul(p[i - 1], B);
	hsh[1] = h[0] - 'a';
	for (int i = 2; i <= (int) h.length(); i++) {
		hsh[i] = add(mod_mul(hsh[i - 1], B), h[i - 1] - 'a');
	}

	vector<int> cnt(26), cur(26);
	for (int i = 0; i < (int) n.length(); i++) {
		cnt[n[i] - 'a']++;
		cur[h[i] - 'a']++;
	}

	set<ll> seen;
	if (cur == cnt) {
		seen.insert(hsh[n.length()]);
	}

	for (int i = n.length() + 1; i <= (int) h.length(); i++) {
		cur[h[i - 1] - 'a']++;
		cur[h[i - n.length() - 1] - 'a']--;

		ll val = sub(hsh[i], mod_mul(p[n.length()], hsh[i - n.length()]));
		if (cur == cnt) seen.insert(val);
	}
	
	cout << sz(seen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    