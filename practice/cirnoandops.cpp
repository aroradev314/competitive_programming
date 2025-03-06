#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

ll fact(int x) {
	ll ans = 1;
	for (int i = 2; i <= x; i++) ans *= i;
	return ans; 
}

ll choose(int a, int b) {
	if (a < b) return 0;
	return fact(a) / (fact(b) * fact(a - b));
}

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n == 1) cout << a[0] << "\n";
	else {
		ll ans = 0;
		while (sz(a) > 1) {
			ll sm = 0;
			for (ll i : a) sm += i;
			if (sz(a) < n) sm = abs(sm);
			ans = max(ans, sm);

			vector<ll> na;
			for (int i = 1; i < sz(a); i++) na.push_back(a[i] - a[i - 1]);
			a = na;
		}
		ans = max(ans, abs(a[0]));

		cout << ans << "\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    