#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    vector<vector<int>> mod(k);
    for (int i = 0; i < n; i++) mod[a[i] % k].push_back(i);

    vector<bool> on(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int flipped = (a[n - 1] - a[i]) / k;
        on[i] = flipped % 2 == 0;
        if (on[i]) tot++;
    }
    
    if (tot == n) {
        cout << a[n - 1] << "\n";
        return;
    }

    for (int add = 1; add <= 2 * k + 2; add++) {
        int cur = a[n - 1] + add;
        for (int i : mod[cur % k]) {
            on[i] = !on[i];
            tot += (on[i] ? 1 : -1);
        }

        if (tot == n) {
            cout << cur << "\n";
            return;
        }
    }
    
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
