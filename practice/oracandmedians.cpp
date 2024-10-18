#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    if (n <= 2) {
        if (n == 1) cout << (a[0] == k ? "yes\n" : "no\n");
        else {
            if (a[0] > a[1]) swap(a[0], a[1]);
            cout << (a[0] == k && a[1] >= k ? "yes\n" : "no\n");
        }
        return;
    }

    bool found = false;
    for (int i = 0; i < n; i++) if (a[i] == k) found = true;
    
    bool other = false;
    for (int i = 2; i < n; i++) {
        int cnt = 0;
        
        for (int j : {0, 1, 2}) cnt += (a[i - j] >= k ? 1 : 0);

        if (cnt >= 2) {
            other = true;
            break;
        }
    }

    cout << (other && found ? "yes\n" : "no\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
