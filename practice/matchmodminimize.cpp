#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    

    int l = 0, r = m - 1;
    while (l <= r) {
        int k = l + (r - l) / 2;
        multiset<int> s;
        for (int i : b) s.insert(i);

        bool works = true;
        for (int i : a) {
            auto it = s.upper_bound(k - i);
            if (it != s.begin()) {
                it--;
                // if (k == 3) cout << i << " " << *it << endl;
                s.erase(it);
            }
            else {
                it = s.upper_bound(m + k - i);
                if (k == 3 && it != s.begin()) cout << *(--it) << endl;
                if (it != s.begin() && *(--it) >= m - i) {
                    // if (k == 3) cout << i << " " << *it << endl;
                    s.erase(it);
                }
                else {
                    works = false;
                    break;
                }
            }
        }

        if (works) r = k - 1;
        else l = k + 1;
    }

    cout << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    