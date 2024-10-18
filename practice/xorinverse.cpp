#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(1, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> a[0][i];

    ll x = 0, tot = 0;

    ll reg, inv, zeros, ones;
    vector<vector<int>> na;
    for (int i = 30; i >= 0; i--) {
        na.clear();
        // if (i == 0) cout << tot << endl;
        reg = 0; inv = 0;
        for (auto vec : a) {
            zeros = 0; ones = 0;
            vector<int> on, off;
            for (int j : vec) {
                // if (i == 0) cout << j << " ";
                if (j & (1 << i)) {
                    on.push_back(j);
                    reg += zeros;
                    ones++;
                }
                else {
                    off.push_back(j);
                    inv += ones;
                    zeros++;
                }
            }
            // if (i == 0) cout << endl;
            if (sz(on)) na.push_back(on);
            if (sz(off)) na.push_back(off);
        }
        // if there are more invs than regs

        // if (inv > 0 || reg > 0) cout << i << " " << inv << " " << reg << endl;

        if (inv > reg) {
            x |= (1 << i);
            tot += reg;
        }
        else tot += inv;

        a = na;
    }

    cout << tot << " " << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
