#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<bool> marked(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];

    marked[0] = true;
    marked[n + 1] = true;

    int cur = -1;
    bool seen = false;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cur == -1 && a[i] > 0) {
            cur = i;
        }
        else if (a[i] == 0 && cur != -1) {
            ans++;
            for (int j = cur; j < i; j++) marked[j] = true;

            if (!marked[cur - 1]) marked[cur - 1] = true;
            else marked[i] = true;
                
            if (seen) marked[i] = true;

            cur = -1;
            seen = false;
        }

        if (a[i] == 2) seen = true;
    }

    if (cur != -1) {
        ans++;
        for (int i = cur - 1; i <= n; i++) marked[i] = true;
    }
    
    for (int i = 1; i <= n; i++) if (!marked[i]) ans++;
    
    
    cout << ans << "\n";
}
