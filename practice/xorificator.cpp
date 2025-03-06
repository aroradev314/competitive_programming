#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

ll f(ll a) {
	if (a < 0) return 0;
	ll res[] = {a, 1, a + 1, 0};
	return res[a % 4];
}

ll res(ll a, int i, ll k) {
	ll mn = 0, mx = 1LL << (62 - i);
	while (mn <= mx) {
		ll mid = mn + (mx - mn) / 2;
		ll n = (mid << i) | k;
		// if (a == 3 && mid == 1) cout << n << endl;
		if (n <= a) mn = mid + 1;
		else mx = mid - 1;
	}
	// cout << a << " " << mn - 1 << endl;

	ll xored = f(mn - 1) << i;
	if ((mn - 1) % 2 == 0) xored ^= k;

	return f(a) ^ xored;
}

void solve() {
    ll l, r, k;
    int i;
    cin >> l >> r >> i >> k;

    ll ans = res(r, i, k) ^ res(l - 1, i, k);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    