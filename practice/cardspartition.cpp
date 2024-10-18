#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll mx = 0, s = 0;
    for (ll i : a) {
        mx = max(mx, i);
        s += i;
    }

    for (ll i = n; i >= 1; i--) {
        ll rem = (i - (s % i)) % i;
        rem = max(rem, mx * i - s);
        // cout << i << " " << rem << " " << k << endl;
        if (k >= rem) {
            cout << i << "\n";
            return;
        }
    }

    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
