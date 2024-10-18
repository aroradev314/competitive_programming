// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <climits>
typedef long long ll;
using namespace std;

int main() {
	ll n;
	int k;
	cin >> n >> k;
	vector<ll> primes(k);
	for (int i = 0; i < k; i++) cin >> primes[i];

	ll ans = 0;
	for (int i = 1; i < (1 << k); i++) {
		int bits = 0;
		ll mul = 1;
		bool overflow = false;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) {
				bits++;
				if (mul > n / primes[j]) {
					overflow = true;
					break;
				}
				mul *= primes[j];
			}
		}
		if (overflow) continue;
		if (bits % 2 == 1) {
			ans += n / mul;
		}
		else {
			ans -= n / mul;
		}
	}
	cout << ans;
}
