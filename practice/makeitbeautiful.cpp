#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<pair<ll, int>> pq;
	
	for (int i = 0; i < n; i++) {
		int b = 0;
		while ((1LL << b) & a[i]) b++;

		pq.push({-(1LL << b), i});
	}

	while (true) {
		auto [d, i] = pq.top();
		pq.pop();
		d = -d;

		if (d <= k) {
			k -= d;
			a[i] |= d;
			int b = 0;
			while ((1LL << b) & a[i]) b++;

			pq.push({-(1LL << b), i});
		}
		else break;
	}

	int ans = 0;
	for (ll i : a) {
		while (i) {
			if (i & 1) ans++;
			i /= 2;
		}
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
    