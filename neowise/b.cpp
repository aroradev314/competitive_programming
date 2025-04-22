#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    vector<int> mx(n), mn(n);
	for (int i = 0; i < n; i++) {
		mx[i] = max(l[i], r[i]);
		mn[i] = min(l[i], r[i]);
	}
	sort(mn.begin(), mn.end());
	reverse(mn.begin(), mn.end());

	ll ans = 0;
	for (int i : mx) ans += i;
	for (int i = 0; i < k - 1; i++) ans += mn[i];
	ans++;

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    