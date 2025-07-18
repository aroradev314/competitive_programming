#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
int d[MAX_N];

void solve() {
    int n;
    cin >> n;

    vector<int> nxt(n + 1, -1);
    nxt[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (d[i] == -1) {
            if (2 * i <= n) {
                nxt[i] = 2 * i;
                nxt[2 * i] = i;
            }
            else nxt[i] = i;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (nxt[i] == -1) {
            nxt[i] = nxt[d[i]];
            nxt[d[i]] = i;
        }
    }

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) arr[i] = nxt[i];

    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void preprocess() {
    fill(d, d + MAX_N, -1);
    for (int i = 2; i < MAX_N; i++) {
        if (d[i] != -1) continue;

        for (int j = i + i; j < MAX_N; j += i) d[j] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    int t;
    cin >> t;
    while (t--) solve();
}
    