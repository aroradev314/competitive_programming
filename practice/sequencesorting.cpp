#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> mn(n + 1), mx(n + 1);
    set<int> nums;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!nums.count(x)) {
            nums.insert(x);
            mn[x] = i;
        }
        mx[x] = i;
    }

    vector<int> a(nums.begin(), nums.end());
    n = a.size();
    vector<int> dp(n, 1);
    int best = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (mx[a[i]] < mn[a[i + 1]]) dp[i] = dp[i + 1] + 1;
        best = max(best, dp[i]);
    }
    
    cout << n - best << "\n";
    

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
