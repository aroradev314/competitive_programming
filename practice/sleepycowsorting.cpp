#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Tree<int> suff;
    suff.insert(a[n - 1]);
    for (int i = n - 2; i >= 0 && a[i] < a[i + 1]; i--) suff.insert(a[i]);
    

    int beg = suff.size();
    cout << n - beg << "\n";

    for (int i = 0; i < n - beg; i++) {
        int shift = n - 1 - (int) suff.size() + suff.order_of_key(a[i]);
        suff.insert(a[i]);
        cout << shift;
        if (i != n - beg - 1) cout << " ";
    }

}

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int t = 1;
    while (t--) solve();
}
