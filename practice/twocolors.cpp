#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int c[MAX_N];
ll pref[MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
	
    for (int i = 1; i <= m; i++) {
    	cin >> c[i];
    	c[i] = min(c[i], n - 1);
    }
    sort(c + 1, c + m + 1);

	for (int i = 1; i <= m; i++) pref[i] = pref[i - 1] + c[i];

	ll ans = 0;
	for (int i = 2; i <= m; i++) {
		auto it = lower_bound(c + 1, c + m + 1, n - c[i]);
		int pos = it - c;
		if (pos >= i) continue;
		ans += pref[i - 1] - pref[pos - 1] + (i - pos) - (i - pos) * 1LL * (n - c[i]);
	}
	cout << ans * 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    