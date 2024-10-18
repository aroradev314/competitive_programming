#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    vector<ll> dp(n + 1);
    vector<int> last(n + 1);

    dp[1] = -1;
    dp[2] = -1;
    dp[3] = a[3].first - a[1].first;
    last[3] = 0;
    
    pair<ll, ll> mn = {INF, -1};
    for (int i = 4; i <= n; i++) {
        if (mn.first == INF) {
            dp[i] = a[i].first - a[1].first;
            last[i] = 0;
        }
        else {
            dp[i] = a[i].first + mn.first;
            last[i] = mn.second;
        }

        if (dp[i - 2] != -1) {
            mn = min(mn, {dp[i - 2] - a[i - 1].first, i - 2});
        }
    }

    int cur = 1, l = last[n];
    vector<int> col(n + 1);
    for (int i = n; i >= 1; i--) {
        if (i == l) {
            l = last[i];
            cur++;
        }
        col[a[i].second] = cur;
    }
    
    cout << dp[n] << " " << cur << "\n";

        
    for (int i = 1; i <= n; i++) cout << col[i] << " ";
}
