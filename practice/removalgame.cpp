#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    for (int i = 0; i < 2; i++) {
        bool works = true;
        for (int j = 0; j < n; j++) {
            if (a[j] != b[j]) {
                works = false;
                break;
            }
        }

        if (works) {
            cout << "Bob\n";
            return;
        }
        reverse(a.begin(), a.end());
    }

    cout << "Alice\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
