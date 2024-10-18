#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
int ans[MAX_N], sz[MAX_N];
int a[MAX_N];
int cur, n;

void find_sz(int node, int par) {
    sz[node] = 1;
    for (int i : adj[node]) if (i != par) {
        find_sz(i, node);
        sz[node] += sz[i];
    }
}

void dfs(int node, int par) {
    if (par != -1 && (a[par] ^ a[node]) != 0) {
        cur += (a[node] ^ a[par]) * sz[node];
    } 

    for (int v : adj[node]) if (v != par) dfs(v, node);
}

void find_ans(int node, int par, int tot) {
    ans[node] = tot;

    for (int v : adj[node]) if (v != par) {
        int x = sz[v];
        int y = n - x;
        find_ans(v, node, tot + (a[node] ^ a[v]) * (y - x));
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int x, b;
        cin >> x >> b;
        x--; b--;
        adj[x].push_back(b);
        adj[b].push_back(x);
    }

    find_sz(0, -1);

    cur = 0;
    dfs(0, -1);

    find_ans(0, -1, cur);
        
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) adj[i].clear();
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}
