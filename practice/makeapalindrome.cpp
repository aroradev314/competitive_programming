#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    if (k == 1) {
        cout << "YES\n";
        return;
    }

    vector<int> a_sort(a);
    sort(a_sort.begin(), a_sort.end());

    int biggest = a_sort[k - 2];

    vector<int> b;
    for (int i : a) if (i <= biggest) b.push_back(i);

    n = sz(b);
    int l = 0, r = n - 1;
    int rem = 0;
    while (l <= r) {
        int first = 0;
        while (l < n && b[l] == biggest) {
            first++;
            l++;
        }
        int second = 0;
        while (r >= 0 && b[r] == biggest) {
            second++;
            r--;
        }
        rem += abs(first - second);

        if (l >= 0 && r < n && b[l] != b[r]) {
            cout << "NO\n";
            return;
        }
        l++;
        r--;
    }

    if (n - rem >= k - 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    