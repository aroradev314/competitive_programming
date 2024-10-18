#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    int l = 1, r = 1e9;
    
    int first = 0, second = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << mid << endl;
        vector<int> which(1 << m, -1);

        for (int j = 0; j < n; j++) {
            int cur = 0;
            for (int k = 0; k < m; k++) if (a[j][k] >= mid) cur += (1 << k);
            which[cur] = j;
        }

        int all = (1 << m) - 1;
        bool found = false;

        for (int i = 0; i < (1 << m); i++ && !found) {
            for (int j = i; j < (1 << m); j++ && !found) {
                if ((i | j) == all && which[i] != -1 && which[j] != -1) {
                    found = true;
                    first = which[i];
                    second = which[j];
                }
            }
        }

        if (found) l = mid + 1;
        else r = mid - 1;
    }

    cout << first + 1 << " " << second + 1 << "\n";
}

