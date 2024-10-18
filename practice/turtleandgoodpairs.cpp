#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;

    vector<int> ind(26);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int a, int b) { return cnt[a] > cnt[b]; });
    
    int cur = 0;
    vector<char> ans(n);
    for (int i : ind) {
        if (cur >= n) cur = 1;
        for (int j = 0; j < cnt[i]; j++) {
            ans[cur] = (i + 'a');
            cur += 2;
            if (cur >= n) cur = 1;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
} 
