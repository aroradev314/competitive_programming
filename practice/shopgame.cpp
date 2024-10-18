#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].first;
    for (int i = 0; i < n; i++) cin >> items[i].second;

    sort(items.begin(), items.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second > b.second;
    });


    priority_queue<ll> pq;
    ll sm = 0;
    for (int i = 0; i < k; i++) {
        sm += items[i].first;
        pq.push(items[i].first);
    }
    ll cur = 0;
    for (int i = k; i < n; i++) cur += max(0LL, items[i].second - items[i].first);
    if (k == 0) {
        cout << cur << "\n";
        return;
    }

    ll ans = max(0LL, cur - sm);
    for (int i = k; i < n; i++) {
        if (items[i].first < pq.top()) {
            sm -= pq.top();
            pq.pop();
            sm += items[i].first;
            pq.push(items[i].first);
        }
        cur -= max(0LL, items[i].second - items[i].first);
        ans = max(ans, cur - sm);
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
