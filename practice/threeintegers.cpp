#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 1e4;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = INF;
    int na = -1, nb = -1, nc = -1;

    for (int x = 1; x <= 2 * MAX; x++) {
        for (int y = x; y <= 2 * MAX; y += x) {
            int cur = abs(x - a) + abs(y - b);
            
            if (c <= y) {
                cur += abs(c - y);
                if (cur < ans) {
                    na = x;
                    nb = y;
                    nc = y;
                    ans = cur;
                }
                continue;
            }


            int less = (c / y) * y;
            int more = (1 + c / y) * y;
            

            cur += min(abs(c - less), abs(c - more));
            
            if (cur < ans) {
                na = x;
                nb = y;
                nc = (abs(c - less) < abs(c - more) ? less : more);
                ans = cur;
            }
        }
    }
    assert(na != -1);
    cout << ans << "\n";

    cout << na << " " << nb << " " << nc << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
