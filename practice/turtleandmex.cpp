#include <vector>
#include <iostream>
typedef long long ll;
#define int long long
using namespace std;


void solve() {
    int n; 
    ll m;
    cin >> n >> m;
    
    ll best = 0, max_first = 0;
    vector<vector<int> > adj;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> mex(l + 10);
        for (int j = 0; j < l; j++) {
            int num;
            cin >> num;
            if (num < mex.size()) mex[num]++;
        }
        
        bool skipped = false;
        int first = -1, second = -1;
        for (int j = 0; j <= l + 5; j++) {
            if (!mex[j]) {
                if (!skipped) {
                    skipped = true;
                    first = j;
                    max_first = max(max_first, first);
                }
                else {
                    best = max(best, (ll) j);
                    second = j;
                    break;
                }
            }
        }
        while (adj.size() <= second) adj.push_back({});
        adj[first].push_back(second);
    }

    vector<ll> dp(best + 1);
    for (int i = best; i >= 0; i--) {
        dp[i] = max(i, max_first);
        for (int j : adj[i]) dp[i] = max(dp[i], dp[j]);
    }

    ll other_best = -1;
    for (int i = 0; i < min(best + 1, (int) adj.size()); i++) if (adj[i].size() > 1) other_best = max(other_best, dp[i]);
    
    for (int i = 0; i <= best; i++) dp[i] = max(dp[i], other_best);

    ll ans = 0;
    for (int i = 0; i <= min(m, best); i++) ans += dp[i];
    if (m > best) {
        ans += m * (m + 1) / 2;
        ans -= best * (best + 1) / 2;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
