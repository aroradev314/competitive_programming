#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[p[i]] = i;

    int inv = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i + 1; j < n; j++) if (pos[j] < pos[i]) cur++;

        inv += min(cur, n - i - 1 - cur);
    }

    cout << inv << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    