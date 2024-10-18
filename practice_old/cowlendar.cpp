// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll mn = LONG_LONG_MAX;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	ll upper = mn / 4;

	sort(a.begin(), a.end());
	auto last = unique(a.begin(), a.end());
	a.erase(last, a.end());

	n = a.size();
	if (n <= 3) {
		ll ans = (upper * upper + upper) / 2;
		cout << ans;
		return 0;
	}

	vector<ll> candidates = {a[1] - a[0], a[2] - a[0], a[3] - a[0], a[2] - a[1], a[3] - a[1], a[3] - a[2]};

	set<ll> divisors;
	for (ll possible : candidates) {
		for (ll i = 1; i * i <= possible; i++) {
			if (possible % i == 0) {
				if (i <= upper) divisors.insert(i);
				if (possible / i != i && possible / i <= upper) divisors.insert(possible / i);
			}
		}
	}

	ll tot = 0;
	for (ll div : divisors) {
		set<ll> mod;
		for (ll i : a) mod.insert(i % div);
		if (mod.size() <= 3) tot += div;
	}

	cout << tot;

}
