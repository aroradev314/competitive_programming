#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    vector<pair<int, int>> ans;
    if (k % 2 == 1) {
        ans.push_back({x, y});
    }

    for (int i = 1; i <= k / 2; i++) {
        ans.push_back({x + i, y + i});
        ans.push_back({x - i, y - i});
    }
    
    for (auto& [a, b] : ans) cout << a << " " << b << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
