#include <bits/stdc++.h>
using namespace std;

void check(int i, vector<int>& pos, vector<int>& sz, vector<bool>& marked, int& off) {
    int next = pos[i * 2], onext = pos[i * 2 + 1];
    int acc = pos[i] + 1, oacc = pos[i] + sz[i] / 2 + 1;
    if (next > onext) swap(next, onext);
    
    if (acc != next || oacc != onext) {
        if (!marked[i]) {
            marked[i] = true;
            off++;
        }
    }
    else if (marked[i]) {
        marked[i] = false;
        off--;
    }
}

void solve() {
    int n, q, trash;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) cin >> trash;

    vector<int> a(n + 1), pos(n + 1), sz(n + 1);
    sz[1] = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 2; i <= n; i++) sz[i] = (sz[i / 2] - 1) / 2;
    
    int off = 0;
    vector<bool> marked(n + 1);
    for (int i = 1; i <= n / 2; i++) {
        check(i, pos, sz, marked, off);
    }


    while (q--) {
        int x, y;
        cin >> x >> y;
        swap(pos[a[x]], pos[a[y]]);
        swap(a[x], a[y]);
        
        if (a[x] <= n / 2) check(a[x], pos, sz, marked, off);
        if (a[y] <= n / 2) check(a[y], pos, sz, marked, off);
        if (a[x] > 1) check(a[x] / 2, pos, sz, marked, off);
        if (a[y] > 1) check(a[y] / 2, pos, sz, marked, off);
        

        cout << (off == 0 ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
