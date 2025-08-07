#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    ll s, x;
    cin >> n >> s >> x;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> pref(n + 1);
    map<ll, ll> cnt;

    ll ans = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];

        if (a[i] == x) {
            for (int j = last; j < i; j++) cnt[pref[j]]++;
            last = i;
        }
        else if (a[i] > x) {
            cnt.clear();
            last = i;
        }

        // cout << i << " " << cnt[pref[i] - s] << endl;
        ans += cnt[pref[i] - s];
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    