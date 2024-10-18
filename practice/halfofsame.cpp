#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_NUM = 2e6;
int a[MAX_N + 10];
int cnt[MAX_NUM + 10];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) cur++;
        else {
            if (cur >= n / 2) {
                cout << "-1\n";
                return;
            }
            cur = 1;
        }
    }
    if (cur >= n / 2) {
        cout << "-1\n";
        return;
    }
    
    set<int> candidates;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int m = a[j] - a[i];
            for (int k = 1; k * k <= m; k++) {
                if (m % k == 0) {
                    candidates.insert(k);
                    if (m / k != k) candidates.insert(m / k);
                }
            }
        }
    }
    

    vector<int> v(candidates.begin(), candidates.end());
    sort(v.begin(), v.end());
    int ans = -1;
    for (int k = v.size() - 1; k >= 0 && ans == -1; k--) {
        int i = v[k];
        for (int j = 0; j < n; j++) {
            int y = (i + a[j] % i) % i;
            cnt[y]++;
            if (cnt[y] == n / 2) {
                ans = i;
                break;
            }
        }
        
        for (int j = 0; j < n; j++) {
            int y = (i + a[j] % i) % i;
            cnt[y] = 0;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
