#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    
    if (n == 1) {
        cout << (k % x[0] == 0 ? "YES\n" : "NO\n");
        return;
    }

    
    for (int i = 1; i < n; i++) x[i] -= x[0];
    k -= x[0];

    ll z = x[1];
    for (int i = 2; i < n; i++) z = gcd(z, x[i]);

    if (k % z == 0) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
