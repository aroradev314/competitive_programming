#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;

    ll g = gcd(a, b);
    if (a / g <= k && b / g <= k) cout << 1 << "\n";
    else cout << 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    