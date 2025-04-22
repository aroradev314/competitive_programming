#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int lc = 0, ic = 0, tc = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'L') lc++;
    	else if (s[i] == 'I') ic++;
    	else tc++;
    } 

    char L = 'L', I = 'I', T = 'T';
    if (lc > ic) {
    	swap(L, I);
    	swap(lc, ic);
    }
    if (ic > tc) {
    	swap(I, T);
    	swap(ic, tc);
    }
    if (lc > ic) {
    	swap(L, I);
    	swap(lc, ic);
    }

    for (int i = 0; i < n; i++) {
    	if (s[i] == 'L') s[i] = L;
    	else if (s[i] == 'I') s[i] = I;
    	else s[i] = T;
    }

    vector<int> ans;
    vector<char> cur;
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
        cur.push_back(s[i]);
        if (found) continue;
        if (s[i] == 'T' && s[i + 1] == 'I') {
            int x = 0;
            vector<char> add;
            found = true;
            while (lc < tc && ic < tc) {
                if (x % 2 == 0) {
                    lc++;
                    add.push_back('L');
                }
                else {
                    ic++;
                    add.push_back('I');
                }
                ans.push_back(i);
                x++;
            }
            reverse(add.begin(), add.end());
            for (char c : add) cur.push_back(c);
        }
        if (s[i] == 'T' && s[i + 1] == 'L') {
            int x = 0;
            vector<char> add;
            found = true;
            while (lc < tc && ic < tc) {
                if (x % 2 == 0) {
                    ic++;
                    add.push_back('I');
                }
                else {
                    lc++;
                    add.push_back('L');
                }
                ans.push_back(i);
                x++;
            }
            reverse(add.begin(), add.end());
            for (char c : add) cur.push_back(c);
        }
        else if (s[i] == 'I' && s[i + 1] == 'T') {
            int x = 0;
            vector<char> add;
            found = true;
            while (lc < tc && ic < tc) {
                if (x % 2 == 0) {
                    lc++;
                    add.push_back('L');
                }
                else {
                    ic++;
                    add.push_back('I');
                }
                ans.push_back(x + i);
                x++;
            }
            for (char c : add) cur.push_back(c);
        }
        else if (s[i] == 'L' && s[i + 1] == 'T') {
            int x = 0;
            vector<char> add;
            found = true;
            while (lc < tc && ic < tc) {
                if (x % 2 == 0) {
                    ic++;
                    add.push_back('I');
                }
                else {
                    lc++;
                    add.push_back('L');
                }
                ans.push_back(x + i);
                x++;
            }
            for (char c : add) {
                cur.push_back(c);
            }
        }
    }
    cur.push_back(s[n - 1]);

    for (int i = sz(cur) - 2; i >= 0; i--) {
        if (lc < tc && ((cur[i] == 'I' && cur[i + 1] == 'T') || (cur[i] == 'T' && cur[i + 1] == 'I'))) {
            lc++;
            ans.push_back(i);
        }
        if (ic < tc && ((cur[i] == 'L' && cur[i + 1] == 'T') || (cur[i] == 'T' && cur[i + 1] == 'L'))) {
            ic++;
            ans.push_back(i);
        }
    }

    if (lc == ic && ic == tc) {
        assert(sz(ans) < 2 * n);
        cout << sz(ans) << "\n";
        for (int i : ans) cout << i + 1 << "\n";
    }
    else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    