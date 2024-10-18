#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 3e5 + 10;

int ninv[MAX_N];

int add(int a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}

int mul(int a, int b) {
    return (int) (((long long) a * b) % MOD);
}

int binexp(int a, int b) {
    if (b == 0) return 1;
    int ans = binexp(a, b / 2);
    ans = mul(ans, ans);
    if (b % 2) ans = mul(ans, a);

    return ans;
}

int inv(int a) {
    return binexp(a, MOD - 2);
}

int main() {
    for (int i = 1; i < MAX_N; i++) ninv[i] = inv(i);

    int n, m;
    string s;
    cin >> n >> m >> s;
    
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '?') ans = mul(ans, i);
    }
    
    cout << (s[0] == '?' ? 0 : ans) << "\n";
    while (m--) {
        int i;
        char c;
        cin >> i >> c;
        i--;

        if (i != 0) {
            if (s[i] == '?') ans = mul(ans, ninv[i]);
            if (c == '?') ans = mul(ans, i);
        }
        s[i] = c;
        

        cout << (s[0] == '?' ? 0 : ans) << "\n";
    }
}
