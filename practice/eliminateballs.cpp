#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 2e9;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n + 2);
    vector<ll> pref(n + 2);
    a[0] = a[n + 1] = -1;
    map<int, vector<int>> pos;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        pos[a[i]].push_back(i);
    }
    pref[n + 1] = pref[n];

    vector<int> before(n + 1, -1), after(n + 1);
    stack<pair<int, int>> s;

    s.push({INF, 0});

    for (int i = 1; i <= n; i++) {
        while (s.top().first <= a[i]) s.pop();
        before[i] = s.top().second;
        s.push({a[i], i});
    }
    
    while (s.size()) s.pop();
    s.push({INF, n + 1});
    for (int i = n; i >= 1; i--) {
        while (s.top().first <= a[i]) s.pop();
        after[i] = s.top().second;
        s.push({a[i], i});
    }

    
    int ans = 0;
    vector<bool> works(n + 2);
    for (auto it = pos.rbegin(); it != pos.rend(); it++) {
        auto where = it->second;

        for (int i : where) {
            if (before[i] == 0 && after[i] == n + 1) {
                works[i] = true;
                ans++;
                continue;
            }

            ll tot = pref[after[i] - 1] - pref[before[i]];
            works[i] = (tot >= a[before[i]] && works[before[i]]) || (tot >= a[after[i]] && works[after[i]]);
            if (works[i]) ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
