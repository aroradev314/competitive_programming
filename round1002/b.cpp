#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = k / 2 + 1;
    for (int i = 2; i <= n; i++) {
    	int even_left = (i - 1) / 2;
    	int even_right = (n - i) / 2;
    	int rem = even_left + even_right + 1 - (k / 2);

    	int even_start = even_left - min(even_left, rem);
    	if (even_start + 1 != a[i]) ans = min(ans, even_start + 1);
    	else if (even_start + 1 <= even_left && even_start + 2 <= k / 2) ans = min(ans, even_start + 2);
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
    