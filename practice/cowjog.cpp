#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
int p[MAX_N];
int s[MAX_N];

void solve() {
	int n;
	ll t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> p[i] >> s[i];

	multiset<ll> dp;
	dp.insert(p[0] + s[0] * t);
	for (int i = 1; i < n; i++) {
		ll cur = p[i] + s[i] * t;
		auto it = dp.lower_bound(cur);
		if (it == dp.begin()) dp.insert(cur);
		else {
			it--;
			dp.erase(it);
			dp.insert(cur);
		}
	}
	cout << sz(dp);
}

int main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    