#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = n - 2; i >= 0; i -= 2) {
        int rem = min(k, a[i + 1] - a[i]);
        a[i] += rem;
        k -= rem;
        ans += a[i + 1] - a[i];
    }
    if (n % 2 == 1) ans += a[0];
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
