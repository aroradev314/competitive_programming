#include <iostream>
#define ll long long
using namespace std;

bool valid(ll n, ll k, ll m, ll x) {
	ll g = 0;
	while (k > 0 && g < n) {
		ll y = (n - g) / x;
		if (y < m) {
			ll leftover = ((n - g) + (m - 1)) / m;
			return leftover <= k;
		}
		ll maxmatch = n - x * y;
		ll numDays = min((maxmatch - g) / y + 1, numDays);
		g += numDays * y;
		k -= numDays;
	}
	return g >= n;
}

int main() {
	freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
	ll n, k, m;
	cin >> n >> k >> m;
	
	ll l = 1, r = 100, ans = 1;
	while (l <= r) {
		ll middle = (l + r) / 2;
		if (valid(n, k, m, middle)) {
			l = middle + 1;
			ans = middle;
		}
		else {
			r = middle - 1;
		}
	}
	cout << ans << endl;
}
		
		
		
