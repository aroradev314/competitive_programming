#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int m = s.length();


    int right = 0, down = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'R') right++;
        else down++;
    }

    if (right == 0 || down == 0) {
        cout << n << "\n";
        return;
    }

    // how many places can we go minus the number of places the person behind me could have also gone
    // could have also gone is how many places they could have gone minus the unique new places that were added by me
    //

    int ways = 0;
    int x = 1, y = 1;
    int ans = 1;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'R') {
            x++;
            right--;
        }
        else {
            y++;
            down--;
        }

        int a = (x > 1 ? n - right - x + 1 : 1);
        int b = (y > 1 ? n - down - y + 1 : 1);

        int unique;
        if (s[i] == 'D') unique = n - y + 1;
        else unique = n - x + 1;

        ans += a * b - ways + unique;
        ways = a * b;
        cout << ans << endl;
    }


    cout << ans << "\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}
