#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), last(n + 1, -1);
    vector<vector<int>> pos(n + 1);
    set<pair<int, int>> last_pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
        pos[a[i]].push_back(i);
    }
    
    for (int i = 1; i <= n; i++) if (last[i] != -1) last_pos.insert({last[i], i});
    
    int l = 1;
    int r = (*last_pos.begin()).first;
    
    set<pair<int, int>> lower;

    auto upper_cmp = [](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.first != y.first) return x.first > y.first;
        else return x.second < y.second;
    };
    set<pair<int, int>, decltype(upper_cmp)> upper(upper_cmp);
    for (int i = l; i <= r; i++) {
        lower.insert({a[i], i});
        upper.insert({a[i], i});
    }
    

    int odd = 1;
    vector<int> ans;
    set<int> chosen;
    while (last_pos.size()) {
        pair<int, int> which;
        assert(upper.size());
        if (odd) which = *upper.begin();
        else which = *lower.begin();

        ans.push_back(which.first);
        chosen.insert(which.first);
        int nl = which.second + 1;
        
        for (int i = l; i < nl; i++) {
            upper.erase({a[i], i});
            lower.erase({a[i], i});
        }
        for (int i : pos[which.first]) {
            upper.erase({a[i], i});
            lower.erase({a[i], i});
        }
        
        last_pos.erase({last[which.first], which.first});
        int nr = (*last_pos.begin()).first;
        for (int i = r + 1; i <= nr; i++) {
            if (!chosen.count(a[i])) {
                upper.insert({a[i], i});
                lower.insert({a[i], i});
            }
        }


        l = nl;
        r = nr;
        odd = !odd;
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
