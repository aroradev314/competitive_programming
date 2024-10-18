#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segs(m + 1);
    for (int i = 1; i <= m; i++) cin >> segs[i].first >> segs[i].second;

    sort(segs.begin(), segs.end());
    
    vector<int> dp(m + 1);
    set<pair<int, int>> right;
    set<int> ind;

    right.insert({})

    for (int i = 1; i <= m; i++) {
        while (sz(right) && *right.begin() < i) {
            ind.erase((*right.begin()).second);
            right.erase(right.begin());
        }
        dp[i] = max(dp[i - 1], )

    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
