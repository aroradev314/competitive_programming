#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

int n, m;
string s = "narek";

int mod_m(int x) {
    while (x < 0) x += 5;
    while (x >= 5) x -= 5;
    return x;
}

bool inside(char c) {
    for (int i = 0; i < 5; i++) if (s[i] == c) return true;
    return false;
}

void solve() {
    cin >> n >> m;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    vector<int> dp(5, -1e9);
    vector<bool> found(5);
    dp[4] = 0;
    found[4] = true;

    for (int i = 0; i < n; i++) {
        string cur = words[i];
        vector<int> ndp = dp;

        for (int j = 0; j < 5; j++) {
            if (!found[mod_m(j - 1)]) continue;

            int start = j;
            int diff = 0;
            
            for (int k = 0; k < cur.length(); k++) {
                if (cur[k] == s[start]) {
                    start++;
                    if (start == 5) {
                        diff += 5;
                        start = 0;
                    }
                }
                else if (inside(cur[k])) diff--;
            }
            
            start = mod_m(start - 1);

            if (!found[start] || dp[mod_m(j - 1)] + diff > ndp[start]) {
                ndp[start] = dp[mod_m(j - 1)] + diff;
                found[start] = true;
            }
        }
        dp = ndp;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) ans = max(ans, dp[i] - mod_m(i + 1));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
