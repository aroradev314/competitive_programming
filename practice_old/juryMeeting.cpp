#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

ll binpow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll ans = binpow(a, b / 2);
	ans = (ans * ans) % MOD;
	
	if (b % 2 == 1) {
		ans = (ans * a) % MOD;
	}
	return ans;
}

ll inv(ll a) {
	return binpow(a, MOD - 2);
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		int mx = *max_element(a.begin(), a.end());
		int cmx = count(a.begin(), a.end(), mx);
		int k = count(a.begin(), a.end(), mx - 1);
		
		ll ans = 1;
		for (int i = 2; i <= n; i++) {
			ans = (ans * i) % MOD;
		}
		
		if (cmx == 1) {
			ll rm = (ans * inv(k + 1)) % MOD;
			ans = (ans - rm + MOD) % MOD;
		}
		
		cout << ans << "\n";
	}
}
		
		
	
	
