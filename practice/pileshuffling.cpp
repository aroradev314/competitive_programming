#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // if we have more ones than we need, remove all zeros until we can 
        if (b > d) {
            ans += max(a - c, 0LL);
            a = min(a, c);
            ans += a;
        }
        ans += max(a - c, 0LL);
        ans += max(b - d, 0LL);
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
    