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

    ll ans = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            int diff = a[i] + a[j] - max(a[n - 1], 2 * a[i]);
            int needed = 1 - diff;

            int k = lower_bound(a.begin(), a.end(), needed) - a.begin();
            if (k < j) ans += j - k;
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
    