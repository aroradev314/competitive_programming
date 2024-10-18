#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), cnt(n + 1);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int i = n - 1, j = n - 1;
    
    while (i >= 0 && j >= 0) {
        while (j > 0 && b[j] == b[j - 1]) {
            cnt[b[j]]++;
            j--;
        }
        if (a[i] == b[j]) {
            i--;
            j--;
        }
        else if (cnt[a[i]] == 0) {
            cout << "NO\n";
            return;
        }
        else {
            cnt[a[i]]--;
            i--;
        }
    }

    while (i >= 0) {
        if (cnt[a[i]] == 0) {
            cout << "NO\n";
            return;
        }
        cnt[a[i]]--;
        i--;
    }
    
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
