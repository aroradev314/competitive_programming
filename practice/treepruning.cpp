#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 5e5 + 10;
vector<int> adj[MAX_N];
int sub[MAX_N], par[MAX_N];
vector<int> deep;

void dfs(int u, int p, int depth) {
    sub[u] = 1;
    deep[u] = depth;
    par[u] = p;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u, depth + 1);
        sub[u] += sub[v];
        deep[u] = max(deep[u], deep[v]);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    deep.resize(n);
    dfs(0, -1, 0);

    sort(deep.begin(), deep.end());
    reverse(deep.begin(), deep.end());

    vector<int> cur = {0};

    int ans = n - 1;
    int dist = 0, removed = 0;
    vector<int> ncur;
    while (!cur.empty()) {
        int tot = 0;
        for (int u : cur) tot += sub[u] - 1;
        ans = min(ans, tot + removed);

        ncur.clear();
        for (int u : cur) {
            for (int v : adj[u]) if (v != par[u]) ncur.push_back(v);
        }
        cur = ncur;
        
        while (sz(deep) && deep.back() < dist + 1) {
            deep.pop_back();
            removed++;
        }
        dist++;
    }
    
    cout << ans << "\n";

    for (int i = 0; i < n; i++) adj[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
