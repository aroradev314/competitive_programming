#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

const int MAX_N = 2e5 + 10;
int fact[MAX_N];

const int MOD = 1e9 + 7;

int mul(int a, int b) {
    return (int) ((1LL * a * b) % MOD);
}

int add(int a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}

void inc(int& a, int b) {
    a = add(a, b);
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

int choose(int a, int b) {
    return mul(fact[a], inv(mul(fact[b], fact[a - b])));
}

void solve() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    // ur last one has to be a right otherwise you will overcount
    // down + b - 1 choose down

    int ans = 0;
    for (int down = 0; down < h - a; down++) {
        // cout << down + b << " " << b << " " << w - b - 1 << " " << h - down - 1 << endl;
        inc(ans, mul(choose(down + b - 1, down), choose(w - b - 1 + h - down - 1, h - down - 1)));
        
        // cout << ans << endl;
    }

    cout << (int) ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fact[0] = 1;

    for (int i = 1; i < MAX_N; i++) fact[i] = mul(fact[i - 1], i);

    int t = 1;
    while (t--) solve();
}
