#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;

    int l = 2, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << "? " << mid << " ";
        for (int i = 1; i <= mid; i++) cout << i << " ";
        cout << endl;

        int f;
        cin >> f;
        if (f > 0) r = mid - 1;
        else l = mid + 1;
    } 

    int o, c;
    if (r == n) {
        o = n;
        c = 1;
    }
    else {
        o = r;
        c = r + 1;
    }

    vector<char> ans(n + 1);
    for (int i = 1; i <= n; i += 2) {
        int x = i, y = (i + 1 <= n ? i + 1 : i);
        cout << "? 6 ";

        cout << x << " " << c << " " << y << " " << c << " " << o << " " << c << endl;

        int f;
        cin >> f;
        if (f == 2) {
            ans[x] = '(';
            ans[y] = ')';
        }
        else if (f == 6) {
            ans[x] = '(';
            ans[y] = '(';
        }
        else if (f == 1) {
            ans[x] = ')';
            ans[y] = ')';
        }
        else {
            ans[x] = ')';
            ans[y] = '(';
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    