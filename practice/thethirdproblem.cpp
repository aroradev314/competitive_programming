#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mul(int a, int b) {
    return (int) ((a * 1LL * b) % MOD);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int l = pos[0], r = pos[0];
    int ans = 1;
    
    
    for (int i = 1; i <= n; i++) {
        if (pos[i] < l) l = pos[i];
        else if (pos[i] > r) r = pos[i];
        else {
            ans = mul(ans, r - l + 1 - i); 
        }
    }

    cout << ans << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
