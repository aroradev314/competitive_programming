#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ld> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    ld l = 1e-6, r = n + 10;
    ld eps = 1e-9;
    
    // minimize miles per second -> maximize seconds per mile 
    // if we undercut it then we need to reduce seconds per mile 
    
    ld ONE = 1.0;
    for (int i = 0; i < 100; i++) {
        ld mid = l + (r - l) / 2;
        bool less = false;
        ld sec_per_mile = ONE / mid;
        for (int j = 1; j <= n; j++) {
            if (j * sec_per_mile > b[j]) {
                less = true;
                break;
            }
        }
        // cout << mid << " " << less << endl;
        if (less) l = mid;
        else r = mid;
    }

    bool valid = true;
    ld sec_per_mile = ONE / l;
    for (int j = 1; j <= n; j++) {
        if (sec_per_mile * j + eps < a[j] || sec_per_mile * j - eps > b[j]) valid = false;
    }

    cout << fixed << setprecision(10) << (valid ? l : -1) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
