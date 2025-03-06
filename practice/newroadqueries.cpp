#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
pair<int, int> edges[MAX_N];
int ans[MAX_N];

void ck_min(int& a, int b) {
    if (a == -1 || b < a) a = b;
}

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
        if (v < 0 || v > n - 1 || u < 0 || u > n - 1) return false;
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



void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[i] = {a, b};
    }

    DSU dsu(n);
    vector<vector<pair<int, int>>> tree(n);
    for (int i = 0; i < m; i++) {
        int a = edges[i].first, b = edges[i].second;

        if (dsu.findpr(a) == dsu.findpr(b)) continue;
        else {
            dsu.unite(a, b);
            tree[a].push_back({b, i + 1});
            tree[b].push_back({a, i + 1});
        }
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    