#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 10;
int a[MAX_N];
int last[MAX_N];
int cnt[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        last[a[i]] = i;
        cnt[a[i]]++;
    }

    int cur = 0;
    int ans = 0;
    while (cur < n) {
        int end = last[a[cur]];
        int best = cnt[a[cur]];
        int start = cur;
        while (cur <= end) {
            end = max(end, last[a[cur]]);
            best = max(best, cnt[a[cur]]);
            cur++;
        }
        
        // cout << start << " " << end << " " << best << endl;
        ans += (end - start + 1) - best;
    }
    
    cout << ans;
}
