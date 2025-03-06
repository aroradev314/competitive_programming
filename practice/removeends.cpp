#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a = {0};
    bool sign = false;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (i == 0 || ((x > 0) == sign)) {
    		a.back() += x;
    	}
    	else {
    		a.push_back(x);
    	}
    	sign = (x > 0);
    }

    ll cur = 0;
    n = sz(a);	
    for (ll i : a) if (i < 0) cur += abs(i);

    ll ans = cur;
	for (ll i : a) {
		if (i < 0) cur -= abs(i);
		else cur += i;
		ans = max(ans, cur);
	}

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    