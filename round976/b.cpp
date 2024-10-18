#include <bits/stdc++.h>
#include <cmath>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    ll k;
    cin >> k;
    ll l = k, r = 2 * k;

    while (l <= r) {
        ld mid = l + (r - l) / 2;
        // how many perfect squares are in 1 ... mid

        ll root = floor(sqrt(mid * 1.0));
        if (mid - root >= k) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
