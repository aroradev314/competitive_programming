#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

	ll ans = 1e18;
	int l = 0, r = 0;
	while (r < n) {
		if (a[l] != a[r]) l = r;
		ans = min(ans, (n - (r - l + 1)) * 1LL * a[l]);
		r++;
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
    