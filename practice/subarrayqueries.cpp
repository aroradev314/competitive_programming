#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> cnt(2 * n + 10);
    multiset<int> best;

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (i >= k) {
            int remove = a[i - k] - (i - k) + n;
            best.erase(best.find(cnt[remove]));
            cnt[remove]--;
            best.insert(cnt[remove]);
        }


        int cur = a[i] - i + n;
        assert(cur >= 0);

        if (cnt[cur] != 0) best.erase(best.find(cnt[cur]));
        cnt[cur]++;
        best.insert(cnt[cur]);



        ans[i] = k - *(--best.end());
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        cout << ans[r] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
