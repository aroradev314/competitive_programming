#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve(int tt) {
    int n, q;
    string s;
    cin >> n >> q >> s;

    set<int> ba, bc, ca, cb;

    for (int i = 0; i < q; i++) {
        char x, y;
        cin >> x >> y;
        if (x == 'b' && y == 'a') ba.insert(i);
        else if (x == 'b' && y == 'c') bc.insert(i);
        else if (x == 'c' && y == 'a') ca.insert(i);
        else if (x == 'c' && y == 'b') cb.insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (sz(ba)) {
                s[i] = 'a';
                ba.erase(ba.begin());
            }
            else if (sz(bc) && sz(ca)) {
                auto it = ca.upper_bound(*bc.begin());
                if (it != ca.end()) {
                    s[i] = 'a';
                    bc.erase(bc.begin());
                    ca.erase(it);
                }
            }
        }
        else if (s[i] == 'c') {
            if (sz(ca)) {
                s[i] = 'a';
                ca.erase(ca.begin());
            }
            else if (sz(cb)) {
                auto it = ba.upper_bound(*cb.begin());
                if (it != ba.end()) {
                    s[i] = 'a';
                    cb.erase(cb.begin());
                    ba.erase(it);
                }
                else {
                    s[i] = 'b';
                    cb.erase(cb.begin());
                }
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) solve(tt);
}
    