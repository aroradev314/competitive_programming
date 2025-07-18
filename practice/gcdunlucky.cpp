#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int cur = lcm(a[0], b[0]);
    for (int i = 0; i < n; i++) {
        cur = gcd(cur, lcm(a[i], b[i]));
        if (cur != a[i]) {
            cout << "NO\n";
            return;
        }
    }

    cur = lcm(b[n - 1], a[n - 1]);
    for (int i = n - 1; i >= 0; i--) {
        cur = gcd(cur, lcm(a[i], b[i]));
        if (cur != b[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    