#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<char> end;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'T') cnt++;
        else end.push_back(s[i]);
    } 

    for (int i = 0; i < cnt; i++) cout << 'T';
    for (char i : end) cout << i;

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    