#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), mn(n + 1, n + 1), mx(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mn[a[i]] = min(mn[a[i]], i);
        mx[a[i]] = max(mx[a[i]], i);
    }

    for (int i = 1; i <= n; i++) {
        mn[i] = min(mn[i], mn[i - 1]);
        mx[i] = max(mx[i], mx[i - 1]);

        if (mx[i] - mn[i] + 1 > i) {
            cout << "0\n";
            return;
        }
    }

    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        l = max(l, i - a[i] + 1);
        r = min(r, i + a[i] - 1);
    }
    
    cout << r - l + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
