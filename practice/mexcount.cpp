#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(n + 1);
    for (int i : a) cnt[i]++;

    vector<pair<int, int>> rng;
    
    int tot = 0;
    for (int i = 0; i <= n; i++) {
        // to make i the mex, we need to remove all i's
        // we can remove every value before that and all the values after that
        rng.push_back({cnt[i], n - i});
        tot += cnt[i];

        if (cnt[i] == 0) break;
    }
    sort(rng.begin(), rng.end());

    multiset<int> s;
    int it = 0;
    for (int i = 0; i <= n; i++) {
        while (it < sz(rng) && rng[it].first == i) {
            s.insert(rng[it].second);
            it++;
        }
        while (sz(s) && *s.begin() < i) s.erase(s.begin());

        cout << sz(s) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    