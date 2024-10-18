#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(n + 1); 
    
    sort(a.begin(), a.end());
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > mx) mx = cnt[a[i]];
    }

    for (int i = 0; i < n; i++) b[i] = a[(i + mx) % n];

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
}


// 2 4 7 7 2 5 4
