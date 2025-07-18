#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 10;
int fact[MAX_N], inv_fact[MAX_N];

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;

    return a;
}

int binpow(int a, int b) {
    // cout << a << " " << b << endl;
    if (b == 0) return 1;

    int ans = binpow(a, b / 2);
    ans = mul(ans, ans);

    if (b % 2) ans = mul(ans, a);
    return ans;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int choose(int a, int b) {
    if (a < b) return 0;
    int ans = 1;
    for (int i = a - b + 1; i <= a; i++) ans = mul(ans, i);

    ans = mul(ans, inv_fact[b]);
    return ans;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k; 

    int n = add(mul(a - 1, k), 1);

    int ways = choose(n, a);
    int m = add(1, mul(mul(ways, k), b - 1));

    cout << n << " " << m << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    inv_fact[0] = inv(fact[0]);
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv_fact[i] = inv(fact[i]);
    }


    int t;
    cin >> t;
    while (t--) solve();
}
    