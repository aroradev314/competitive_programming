#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

bool nested(int l1, int r1, int l2, int r2) {
    return (l1 >= l2 && r1 <= r2) || (l2 >= l1 && r2 <= r1);
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int x, int y) {
        return a[x].second < a[y].second;
    });

    vector<int> dp(n), par(n, -1);

    int ans = 0;
    for (int x = 0; x < n; x++) {
        int i = ind[x];
        dp[x] = a[i].second - a[i].first;

        for (int y = 0; y < x; y++) {
            int j = ind[y];
            if (!nested(a[i].first, a[i].second, a[j].first, a[j].second)) {
                int other = dp[y] + a[i].second - max(a[i].first, a[j].second);
                if (other > dp[x]) {
                    dp[x] = other;
                    par[x] = y;
                }
            }
        }

        if (dp[x] > dp[ans]) ans = x;
        // cout << dp[x] << endl;
    }

    vector<int> s;
    while (ans != -1) {
        s.push_back(ind[ans]);
        ans = par[ans];
    }
    reverse(s.begin(), s.end());

    cout << sz(s) << "\n";
    for (int i : s) cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    