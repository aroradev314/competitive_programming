#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll sm = 0;
    for (int i : a) sm += i;

    ll l = a[0], r = (sm + n - 1) / n;
    
    while (r - l > 1) {
        ll mid = l + (r - l) / 2;

        ll less = 0, more = 0;
        for (int i : a) {
            less += max(0LL, mid - i);
            more += max(0LL, i - (mid + k));
        }

        if (more >= less) l = mid;
        else r = mid;
    }
    // every value should be between l and l + k
    ll moves = 0, exc = 0, excs = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < l) {
            moves += l - a[i];
            a[i] = l;
        }
        else if (a[i] > l + k) {
            exc += a[i] - (l + k);
            excs++;
            a[i] = l + k;
        }
    }

    exc -= moves;
    for (int i = 0; i < min(exc, excs); i++) a[n - 1 - i]++;
    exc -= excs;
    // for (int i : a) cout << i << " ";
    // cout << "\n";

    // cout << exc << " " << excs << endl;
    
    for (int i = 0; i < exc; i++) {
        a[i]++;
        moves++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += (a[i] * (a[i] + 1)) / 2;
    ans += moves * k;

    // for (int i : a) cout << i << " ";
    // cout << "\n";

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    