#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

vector<ll> bad;
ll MX = 1e18;

ll good(ll x) {
    ll good = 0;
    vector<ll> p = {2, 3, 5, 7};

    for (int i = 1; i < (1 << sz(p)); i++) {
        ll par = 0, mul = 1;
        for (int j = 0; j < sz(p); j++) {
            if ((1 << j) & i) {
                par = 1 - par;
                mul *= p[j];
            }
        }
        if (par) good += x / mul;
        else good -= x / mul;
    }

    return x - 1 - good;
}

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << good(r) - good(l - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    