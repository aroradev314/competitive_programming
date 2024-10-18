#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);

    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i] >> d[i];


    vector<array<int, 2>> left;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            left.push_back({max(0, c[j] - a[i] + 1), max(0, d[j] - b[i] + 1)});
        }
    }
    sort(left.begin(), left.end());
    
    vector<int> mx(n * m + 1);
    mx[n * m] = 0;
    for (int i = n * m - 1; i >= 0; i--) mx[i] = max(mx[i + 1], left[i][1]);


    int cur = 0;
    int ans = 2e9;
    for (int i = 0; i <= 1e6 + 10; i++) {
        while (cur < n * m && left[cur][0] <= i) cur++;
        ans = min(ans, i + mx[cur]);
    }
    cout << ans << "\n";

}
