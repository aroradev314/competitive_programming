#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    ll dist = (xs - xt) * (xs - xt) + (ys - yt) * (ys - yt);

    for (int i = 0; i < n; i++) {
        ll cur = (x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt);
        if (cur <= dist) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
