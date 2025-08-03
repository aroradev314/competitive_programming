#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = n;
    int xl = 1, xr = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        // cout << mid << ":\n";

        int mn = 0, mn_pos = 1;
        vector<int> diff(n + 1);
        bool works = false;
        for (int i = 1; i <= n; i++) {
            diff[i] = diff[i - 1] + (a[i] >= mid ? 1 : -1);
            // if (mid == 3) cout << diff[i] << endl;

            if (i - k >= 0) {
                if (diff[i - k] < mn) {
                    mn = diff[i - k];
                    mn_pos = i - k + 1;
                }
                if (diff[i] >= mn) {
                    works = true;
                    xl = mn_pos;
                    xr = i;
                    break;
                }
            }
        }

        if (works) l = mid + 1;
        else r = mid - 1;
    }

    cout << l - 1 << " " << xl << " " << xr << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    