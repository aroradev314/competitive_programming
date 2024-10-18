#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

int n;

int mod(int a) {
    while (a < 0) a += 2 * n;
    while (a >= 2 * n) a -= 2 * n;
    return a;
}


void solve() {
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    
    int ans = -1;
    vector<int> s(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (a[mod(i + n)] > a[i]) {
            int cur = i;
            while (a[mod(cur - 1 + n)] > a[mod(cur - 1)]) cur = mod(cur - 1);
            cur = mod(cur + n / 2);
            ans = cur;
            for (int j = 0; j < 2 * n; j++) s[j] = a[mod(cur + j)];
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        bool bad = s[i] != s[2 * n - i - 1];
        if (i < n / 2) {
            if (s[n + i] <= s[i]) bad = true;
        }
        else if (i > n / 2) {
            if (s[n + i] >= s[i]) bad = true;
        }

        if (bad) {
            ans = -1;
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
