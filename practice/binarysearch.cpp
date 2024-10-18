#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    vector<pair<int, int>> swaps;

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid;
        else r = mid;
    }

    swaps.push_back({pos[x], l});
    swap(a[pos[x]], a[l]);
    
    for (int i = 1; i <= n; i++) pos[a[i]] = i;

    l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid;
        else r = mid;
    }

    if (a[l] != x) {
        swaps.push_back({pos[x], l});
    }

    
    cout << swaps.size() << "\n";
    for (auto i : swaps) {
        cout << i.first << " " << i.second << "\n";
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
