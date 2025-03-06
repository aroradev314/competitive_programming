#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    set<int> first, second;
    for (int i : a) first.insert(i);
    for (int i : b) second.insert(i);

    if (sz(first) >= 2 && sz(second) >= 2) cout << "YES\n";
    else if (sz(first) >= 3 || sz(second) >= 3) cout << "YES\n";
    else cout << "NO\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    