#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n == 1) {
        if (a[0] < k) cout << k << "\n";
        else cout << k - 1 << "\n";
        return;
    }

    int g = 0;
    for (int i = 0; i < n; i++) g = gcd(g, a[i]);

    int ans = -1;
    for (int i = 1; i < n; i++) {
        if (k <= g - 1) {
            ans = (i - 1) * g + k;
            break;
        }
        else k -= (g - 1);
    }

    if (ans == -1) ans = (n - 1) * g + k;

    cout << ans << "\n";
    

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
