#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct DSU {
    vector<int> pr;
    vector<int> siz;
    int n;
 
    DSU(int x) : n(x) {
        pr.resize(n);
        siz.resize(n, 1);
        iota(pr.begin(), pr.end(), 0);
    }
 
    inline int findpr(int v) {
        while (v != pr[v]) v = pr[v];
        return v;
    }
 
    inline bool unite(int v, int u) {
        if (v < 1 || v > n || u < 1 || u > n) return false;
        v = findpr(v);
        u = findpr(u);

        if (siz[u] < siz[v]) swap(u, v);

        if (u == v) {
            return false;
        } else {
            pr[v] = u;
            siz[u] += siz[v];
            return true;
        }
    }
};

struct Op {
    int a, d, k;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Op> ops(m);
    
    for (int i = 0; i < m; i++) cin >> ops[i].a >> ops[i].d >> ops[i].k;

    sort(ops.begin(), ops.end(), [](Op a, Op b) { return a.a < b.a; });

    DSU dsu(n + 10);
    vector<vector<int>> last(11, vector<int>(11)); // last[i][j] is gaps of i  with mod j
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i - j > 0 && last[j][i % j] >= i - j) {
                dsu.unite(i, i - j);
            }
        }
        while (cur < m && ops[cur].a == i) {
            auto op = ops[cur];
            last[op.d][i % op.d] = max(last[op.d][i % op.d], op.a + (op.k - 1) * op.d);
            cur++;
        }
    }

    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(dsu.findpr(i));

    cout << sz(s) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
