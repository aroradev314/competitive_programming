#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using           namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++) cin >> s[i];
    vector<int> pos;
    for (int i = 0; i < min(130, m); i++) pos.push_back(s[m - 1 - i]);

    vector<int> ans(n + 1);
    vector<vector<bool>> chosen(n + 1, vector<bool>(sz(pos)));
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < sz(pos); j++) {
            if (!chosen[i][j]) {
                found = true;
                ans[i] = j;
                break;
            }
        }
        if (!found) {
            cout << "-1\n";
            return;
        }
        for (int j = i + i; j <= n; j += i) {
            chosen[j][ans[i]] = true;
        }
    } 
    for (int i = 1; i <= n; i++) cout << pos[ans[i]] << " ";
    cout << "\n";
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    