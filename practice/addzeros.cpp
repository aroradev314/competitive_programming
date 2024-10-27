#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, vector<int>> pos;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) pos[a[i] + i].push_back(i);
    stack<ll> s;
	s.push(n);

	ll ans = 0;
	set<ll> seen;
	while (sz(s)) {
		ll len = s.top();
		s.pop();
		ans = max(ans, len);
		if (!pos.count(len) || seen.count(len)) continue;
		seen.insert(len);
		for (int i : pos[len]) {
			s.push(len + i);
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
    