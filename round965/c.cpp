#include <bits/stdc++.h>
#define int long long
using namespace std;

int getind(int n) {
    return n / 2 - (n % 2 == 0 ? 1 : 0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;

    sort(a.begin(), a.end());

    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i].second != 1) continue;
        int med_index = getind(n - 1);
        if (i <= med_index) med_index++;
        ans = max(ans, k + a[i].first + a[med_index].first);
    }
    vector<pair<int, int>> remaining;
    for (int i = 0; i < n - 1; i++) {
        remaining.push_back(a[i]);
    }
    reverse(remaining.begin(), remaining.end());

    int l = 0, r = 1e17;
    
    int left = n - 1;
    while (l <= r) {
        int cur = k;
        int mid = l + (r - l) / 2;
        int cnt = 0;
        for (int i = 0; i < left; i++) {
            if (remaining[i].first >= mid) cnt++;
            else if (mid - remaining[i].first <= cur && remaining[i].second == 1) {
                cur -= mid - remaining[i].first;
                cnt++;
            }
        }
        if (cnt >= (left / 2) + 1) l = mid + 1;
        else r = mid - 1;
    }
    ans = max(ans, a[n - 1].first + l - 1);

    cout << ans << "\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}
