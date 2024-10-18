#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<bool> white(n + 1), black(n + 1), seen(n + 1);
    vector<int> ind(n + 1);

    for (int i = 1; i <= n; i++) ind[a[i]]++;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) if (ind[i] == 0) {
        q.push(i);
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        seen[i] = true;
        if (!white[i] && !black[i]) {
            white[i] = true;
            black[a[i]] = true;
            ind[a[i]] = 0;
            q.push(a[i]);
            continue;
        }

        ind[a[i]]--;
        if (ind[a[i]] == 0) q.push(a[i]);
    }


    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            int cur = a[i];
            int len = 1;
            black[i] = true;
            bool onwhite = true;
            seen[i] = true;

            while (cur != i) {
                seen[cur] = true;
                if (onwhite) white[cur] = true;
                else black[cur] = true;

                len++;
                onwhite = !onwhite;
                cur = a[cur];
            }

            if (len % 2) {
                cout << -1;
                return 0;
            }
        }
    }

        
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (white[i]) ans.push_back(a[i]);
    }
    
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}


