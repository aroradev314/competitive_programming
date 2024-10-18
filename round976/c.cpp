#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    ll b, c, d;
    cin >> b >> c >> d;
    
    ll a = 0, cur = 0;

    for (int i = 61; i >= 0; i--) {
        ll bit = (1LL << i);
        ll first = bit & b;
        ll second = bit & c;
        ll don = bit & d;
        if (first && !second) cur |= bit;
        else if (first && second) {
            if (don) cur |= bit;
            else a |= bit;
        }
        else if (!first && !second) {
            if (don) {
                a |= bit; 
                cur |= bit;
            }
        }
    }
    if (cur == d) cout << a << "\n";
    else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
