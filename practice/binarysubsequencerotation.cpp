#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt++;
        if (t[i] == '1') cnt--;
    }

    if (cnt != 0) {
        cout << -1;
        return;
    }

    vector<char> a;
    for (int i = 0; i < n; i++) if (s[i] != t[i]) a.push_back(s[i]);

    int ans = 0;
    int ones = 0, zeros = 0;

    for (int i = 0; i < sz(a); i++) {
        if (a[i] == '1') {
            if (zeros) zeros--;
            else ans++;
            ones++;
        }
        else {
            if (ones) ones--;
            else ans++;
            zeros++;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
