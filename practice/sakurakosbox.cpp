#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
        
    return a;
}

int mul(int a, int b) {
    return ((a * 1LL * b) % MOD);
}

int binpow(int a, int b) {
    if (b == 0) return 1;
    int ans = binpow(a, b / 2);
    ans = mul(ans, ans);
    if (b % 2) ans = mul(ans, a);

    return ans;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int sm = 0;
    for (int i = 0; i < n; i++) sm = add(sm, a[i]);

    
    int ans = 0;
    for (int i = 0; i < n; i++) ans = add(ans, mul(a[i], add(sm, -a[i])));
    ans = mul(ans, inv(2));
        
    int ways = mul(mul(n, n - 1), inv(2));

    ans = mul(ans, inv(ways));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
