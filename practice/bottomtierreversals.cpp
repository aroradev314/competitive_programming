#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == i % 2) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ans;
    for (int i = n; i > 1; i -= 2) {
        int pos = 0;
        for (int j = 0; j < n; j++) if (a[j] == i) {
            pos = j;
            break;
        }
        ans.push_back(pos + 1);
        reverse(a.begin(), a.begin() + pos + 1);

        int y = 0;
        for (int j = 0; j < n; j++) if (a[j] == i - 1) {
            y = j;
            break;
        }
        
        ans.push_back(y);
        reverse(a.begin(), a.begin() + y);
        ans.push_back(y + 2);
        reverse(a.begin(), a.begin() + y + 2);
        ans.push_back(3);
        reverse(a.begin(), a.begin() + 3);
        ans.push_back(i);
        reverse(a.begin(), a.begin() + i);
    }

    cout << sz(ans) << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
