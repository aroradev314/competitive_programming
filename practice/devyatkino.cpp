#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;


void solve() {
    int n;
    cin >> n;

    int ans = (n % 10) - 7;
    if (ans < 0) ans += 10;
    ans = min(ans, 7);
    for (int i = 0; i <= ans; i++) {
    	int c = n - i;
    	while (c > 0) {
    		if (c % 10 == 7) ans = min(ans, i);
    		int d = 7 - (c % 10);
    		if (d < 0) d += 10;
    		if (d == i) ans = min(ans, i);
    		c /= 10;
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
    