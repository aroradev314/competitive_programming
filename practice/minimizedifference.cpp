#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<pair<ll, int>> s; // i, cnt[i]

    s.push({a[0], 1});

    for (int i = 1; i < n; i++) {
        ll sm = a[i];
        ll cnt = 1;
        while (sz(s) && sm / cnt < s.top().first) {
            sm += s.top().first * s.top().second;
            cnt += s.top().second;
            s.pop();
        }
        s.push({sm / cnt, cnt - (sm % cnt)});
        if (sm % cnt != 0) s.push({sm / cnt + 1, sm % cnt});
    }
    
    ll mx = s.top().first, mn = s.top().first;
    while (sz(s)) {
        mx = max(mx, s.top().first);
        mn = min(mn, s.top().first);
        s.pop();
    }

    cout << mx - mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
