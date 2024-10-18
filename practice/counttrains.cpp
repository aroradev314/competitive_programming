#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> s;
    s.insert(0);
    int cur = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < cur) {
            cur = a[i];
            s.insert(i);
        }
    }

    while (m--) {
        int k, d;
        cin >> k >> d;
        k--;
        a[k] -= d;
        
        if (!s.count(k)) {
            auto it = s.lower_bound(k);
            it--;
            if (a[k] < a[*it]) s.insert(k);
        }

        if (s.count(k)) {
            while (true) {
                auto nxt = s.upper_bound(k);
                if (nxt == s.end()) break;
                if (a[*nxt] >= a[k]) s.erase(nxt);
                else break;
            }
        }
        
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
