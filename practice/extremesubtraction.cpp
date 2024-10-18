#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int _ = 0; _ < 2; _++) {
        int l = 0;
        while (l < n - 1 && a[l] >= a[l + 1]) l++;
        int r = n - 1;
        while (r > 0 && a[r] >= a[r - 1]) r--;

        if (l == n - 1 || r == 0) {
            cout << "YES\n";
            return;
        }
        
        int tot = 0;
        for (int i = l + 1; i < r; i++) {
            tot += max(0, a[i] - a[i - 1]);
        }

        if (tot <= a[r]) {
            cout << "YES\n";
            return;
        }

        reverse(a.begin(), a.end());
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
