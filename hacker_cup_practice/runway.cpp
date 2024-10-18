#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    vector<vector<int>> shows(n, vector<int>(m));

    for (int i = 0; i < m; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> shows[i][j];
    }

    map<int, int> w, u, r; // wearing, unchanged, and required
    for (int i : shows[0]) {
        w[i]++;
        u[i]++;
    }

    for (int i = 0; i < n; i++) {
        r.clear();
        for (int j : shows[i]) r[j]++;

        for (auto [color, amount] : r) {
            
        }

    }
    




    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
