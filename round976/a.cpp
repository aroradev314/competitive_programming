#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k == 1) {
        cout << n << "\n";
        return;
    }

    int cur = 1;
    while (cur * k <= n) cur *= k;

    int ans = 0;
    while (n > 0) {
        ans += n / cur;
        n -= cur * (n / cur);
        cur /= k;
        // cout << n << " " << cur << "\n";
    }
    
    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
