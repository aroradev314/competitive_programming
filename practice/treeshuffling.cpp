#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 2e5 + 10;
ll a[MAX_N];
int b[MAX_N], c[MAX_N], ones[MAX_N], wanted_ones[MAX_N];

vector<int> adj[MAX_N];

ll cost[MAX_N];

void dfs(int u, int p) {
    a[u] = min(a[u], a[p]);
    if (b[u] == 1) ones[u]++;
    if (c[u] == 1) wanted_ones[u]++;

    int x = (b[u] == 0 && c[u] == 1 ? 1 : 0);
    int y = (b[u] == 1 && c[u] == 0 ? 1 : 0);

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        if (ones[v] < wanted_ones[v]) x += wanted_ones[v] - ones[v];
        else y += ones[v] - wanted_ones[v];

        ones[u] += ones[v];
        wanted_ones[u] += wanted_ones[v];
        cost[u] += cost[v];
    }
    
    cost[u] += a[u] * min(x, y) * 2;
    // cout << u << " " << cost[u] << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 1);

    if (ones[1] == wanted_ones[1]) cout << cost[1];
    else cout << -1;
}
