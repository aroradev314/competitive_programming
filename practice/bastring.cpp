#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 1e7 + 10;
char ans[MAX_N];

void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    x--;
    
    string s;
    cin >> s;
    
    vector<int> letters;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') cnt++;
        else {
            if (cnt != 0) letters.push_back(cnt);
            letters.push_back(0);
            cnt = 0;
        }
    }
    if (cnt != 0) letters.push_back(cnt);

    
    vector<ll> vals(letters.size());
    ll tot = 0;
    for (int i = letters.size() - 1; i >= 0; i--) {
        if (tot == -1) {
            vals[i] = -1;
            continue;
        }
        if (letters[i] == 0) continue;
        if (tot == 0) {
            tot = letters[i] * k;
            vals[i] = 1;
            continue;
        }
        vals[i] = tot + 1;
        ll add = (tot + 1) * k * letters[i];
        if (add < 0) tot = -1;
        tot += add;
        if (tot < 0 || tot > x) tot = -1;
    }
    
    int len = 0;
    for (int i = 0; i < letters.size(); i++) {
        if (letters[i] == 0) {
            ans[len++] = 'a';
            continue;
        }
        if (vals[i] == -1) continue;
        
        ll val = vals[i];
        while (x >= val) {
            x -= val;
            ans[len++] = 'b';
        }
    }

    for (int i = 0; i < len; i++) cout << ans[i];

    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
