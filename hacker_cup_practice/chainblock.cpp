#include <vector>
#include <map>
#include <iostream>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e6;
int f[MAX_N], each[MAX_N];
vector<int> adj[MAX_N];

map<int, int> sub[MAX_N];
int complete[MAX_N]; // how many in this subtree have we completely filled out

int ans;

void dfs(int u, int p) {
    sub[u][f[u]]++;
    if (sub[u][f[u]] == each[f[u]]) complete[u]++;
    for (int v : adj[u]) if (v != p) {
        cout << v << endl;
        dfs(v, u);
        complete[u] += complete[v];
        if (sz(sub[u]) < sz(sub[v])) swap(sub[u], sub[v]);
        for (auto& [k, x] : sub[v]) {
            sub[u][k] += x;
            bool zero = (sub[u][k] == x);
            if (sub[u][k] == each[k] && !zero) {
                complete[u]++;
            }
        }
    }

    if (complete[u] == sz(sub[u]) && u != 1) ans++;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        each[f[i]]++;
    }

    ans = 0;
    dfs(1, -1);

    cout << ans << "\n";
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        complete[i] = 0;
        each[i] = 0;
        sub[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
