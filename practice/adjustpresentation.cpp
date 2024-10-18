#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<pair<int, int>>> pos(n + 1);
    Tree<pair<int, int>> global; // {i, a[i]} for all a[i] != a[i - 1], check if they match up with ord
    vector<int> ord(n + 1);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ord[a] = i;
    }

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    global.insert({0, a[0]});
    int cur = a[0], len = 1;
    for (int i = 1; i < m; i++) {
        if (a[i] == cur) len++;
        else {
            pos[cur].insert({i - len, i - 1});
            global.insert({i, a[i]});
            len = 1;
        }
        cur = a[i];
    }
    pos[cur].insert({m - len, m - 1});

    int diff = 0;
    int mx = 0, mn = m + 1;
    vector<bool> wrong(n + 1);
    for (int i = 1; i <= n; i++) {
        mx = max(mx, sz(pos[i]));
        mn = min(mn, sz(pos[i]));
        if (sz(pos[i]) == 0) continue;
        int first = (*pos[i].begin()).first;
        if ((int) global.order_of_key({first, i}) != ord[i]) {
            diff++;
            wrong[i] = true;
        }
    }
    
    cout << (diff == 0 && (mx - mn <= 1) ? "YA" : "TIDAK") << "\n";

    while (q--) {
        int s, t;
        cin >> s >> t;
        s--;

        if (a[s] == t) {
            cout << (diff == 0 && (mx - mn <= 1) ? "YA" : "TIDAK") << "\n";
        }

        int bef = a[s];
        auto [l, r] = *(--pos[bef].upper_bound({s, 0}));
        pos[bef].erase({l, r});
        if (s - 1 >= l) pos[bef].insert({l, s - 1});
        if (s + 1 <= r) pos[bef].insert({s + 1, r});
        
        if (sz(pos[t]) == 0) pos[t].insert({s, s});
        else {
            auto above = pos[t].upper_bound({s, 0});
            auto below = --pos[t].upper_bound({s, 0});
            
            if (above == pos[t].end()) {
                int nl = below -> first, nr = below -> second;
                if (nr + 1 == s) {
                    pos[t].erase(below);
                    pos[t].insert({nl, nr + 1});
                }
                else pos[t].insert({s, s});
            }
            else if (below == pos[t].end()) {
                int nl = above -> first, nr = above -> second;
                if (s + 1 == nl) {
                    pos[t].erase(above);
                    pos[t].insert({nl - 1, nr});
                }
                else pos[t].insert({s, s});
            }
            else {
                int bl = below -> first, br = below -> second;
                int al = above -> first, ar = above -> second;

                if (br + 1 == s && s + 1 == al) {
                    pos[t].erase(above);
                    pos[t].erase(below);
                    pos[t].insert({bl, ar});
                }
                else if (br + 1 == s) {
                    pos[t].erase(below);
                    pos[t].insert({bl, br + 1});
                }
                else if (s + 1 == ar) {
                    pos[t].erase(above);
                    pos[t].insert({al - 1, ar});
                }
                else pos[t].insert({s, s});
            }
        }

        // if ((int) global.order_of_key({bef, }))
        

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
