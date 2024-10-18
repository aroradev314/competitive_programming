#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 10;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    int a = 0, ab = 0, abc = 0;
    
    // say we have x substrings right now
    // adding a question mark can 
    int before = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') (a += before) %= MOD;
        else if (s[i] == 'b') (ab += a) %= MOD;
        else if (s[i] == 'c') (abc += ab) %= MOD;
        else {
            abc = (int) ((abc * 3LL) % MOD) + ab;
            ab = (int) ((ab * 3LL) % MOD) + a;
            a = (int) ((a * 3LL) % MOD) + before;

            abc %= MOD;
            ab %= MOD;
            a %= MOD;

            before = (int) ((before * 3LL) % MOD);
        }
    }
    cout << abc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
