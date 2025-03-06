#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), ans(n + 1, 1);
    vector<map<int, int>> sub(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sub[i][a[i]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (auto [val, len] : sub[i]) {
            ans[len] = max(ans[len], val);
            int new_gcd = gcd(val, a[i + 1]);
            sub[i + 1][new_gcd] = max(sub[i + 1][new_gcd], len + 1);
        }
    }

    for (auto [val, len] : sub[n]) ans[len] = max(ans[len], val);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    