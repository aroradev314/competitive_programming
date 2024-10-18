#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    array<int, 3> d;
    cin >> n >> d[0] >> d[1] >> d[2];
    // d12, d23, d31
    //
    for (int i = 0; i < 3; i++) {
        int tot = (i + 1) % 3;
        int a = (i + 2) % 3, b = i;

        tot = d[tot];
        a = d[a];
        b = d[b];

        if (tot == a + b && tot <= n - 1) {
            cout << "YES\n";
            int root = i + 1; 
            int first, second;
            if (root == 1) {
                first = 3;
                second = 2;
            }
            else if (root == 2) {
                first = 1;
                second = 3;
            }
            else {
                first = 2;
                second = 1;
            }
            
            int cur = root, nxt = 4;
            for (int j = 0; j < a - 1; j++) {
                cout << cur << " " << nxt << "\n";

                cur = nxt;
                nxt++;
            }
            cout << cur << " " << first << "\n";

            cur = root;
            for (int j = 0; j < b - 1; j++) {
                cout << cur << " " << nxt << "\n";
                cur = nxt;
                nxt++;
            }
            cout << cur << " " << second << "\n";
            
            cur = root;
            for (int j = 0; j < n - 1 - a - b; j++) {
                cout << cur << " " << nxt << "\n";
                nxt++;
            }
            
            return;
        }
    }

    if (n == 3){
        cout << "NO\n";
        return;
    }

    for (int i = 1; i <= d[0]; i++) {
        int first = i, second = d[0] - i, third = d[2] - i;
        if (second >= 1 && third >= 1 && first + second + third <= n - 1 && second + third == d[1]) {
            cout << "YES\n";

            int lst = 4, cur = 5;
            
            for (int j = 0; j < first - 1; j++) {
                cout << lst << " " << cur << "\n";
                lst = cur;
                cur++;
            }
            cout << lst << " " << 1 << "\n";
            lst = 4;


            for (int j = 0; j < second - 1; j++) {
                cout << lst << " " << cur << "\n";
                lst = cur;
                cur++;
            }
            cout << lst << " " << 2 << "\n";
            lst = 4;

            for (int j = 0; j < third - 1; j++) {
                cout << lst << " " << cur << "\n";
                lst = cur;
                cur++;
            }
            cout << lst << " " << 3 << "\n";
            lst = 4;

            while (cur <= n) {
                cout << lst << " " << cur << "\n";
                lst = cur;
                cur++;
            }

            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
