#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
int col[MAX_N], ind[MAX_N];
int dp[MAX_N];

void dfs(int u, vector<int>& stack) {
    col[u] = 1;
    stack.push_back(u);
    for (int v : adj[u]) {
        if (col[v] == 1) {
            works = false;
            return;
        }
        else if (col[v] == 0) dfs(v, stack);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ind[i];
        for (int j = 0; j < ind[i]; j++) {
            int c;
            cin >> c;
            adj[c].push_back(i);
        }
    }

    
    queue<int> q;
    for (int i = 1; i <= n; i++) if (ind[i] == 0) {
        q.push(i);
        dp[i] = 1;
    }
    
    
    int ans = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, dp[u]);

        for (int v : adj[u]) {
            int len = dp[u] + (v < u ? 1 : 0);
            dp[v] = max(dp[v], len);
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }

    bool works = true;
    for (int i = 1; i <= n; i++) if (ind[i] != 0) {
        works = false;
        break;
    }

    cout << (works ? ans : -1) << "\n";

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        col[i] = 0;
        dp[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
