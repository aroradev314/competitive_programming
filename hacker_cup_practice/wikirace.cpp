#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e6;
vector<int> adj[MAX_N + 10];
vector<int> topics[MAX_N + 10];
map<int, int> cnt[MAX_N + 10];
int dp[MAX_N + 10], leaves[MAX_N + 10];

void dfs(int u, int p) {
    dp[u] = 0;
    leaves[u] = 0;
    if (sz(adj[u]) == 0) leaves[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        leaves[u] += leaves[v];
    }

    for (int v : adj[u]) if (v != p) {
        if (sz(topics[u]) < sz(topics[v])) swap(topics[u], topics[v]);
        for (auto& [j, c] : cnt[v]) {
            cnt[u][j] += c;
            cnt[u][j] = min(cnt[u][j], leaves[u]);
        }
    }
    
    for (int v : topics[u]) {
        int x = (cnt[u].count(v) ? cnt[u][v] : 0);
        if (x + 1 == leaves[u]) cnt[u][v] += 1;
    }

    
    // cout << endl;
    // cout << u << endl;
    // for (auto& [j, c] : cnt[u]) cout << j << " " << c << endl;

    // if the number of paths through here that contain a topic is equal to the number of leaves, then it is possible
    // we can add one from this 
}

void solve(int test_case) {
    int n;
    cin >> n;
    

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    map<string, int> id;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            string s;
            cin >> s;
            if (!id.count(s)) id[s] = cur++;
            topics[i].push_back(id[s]);
        }
    }

    
    // cout << endl;
    // for (auto& [s, i] : id) cout << s << " " << i << endl;
    // cout << endl;

    dfs(1, -1);

    int ans = 0;
    for (auto& [k, v] : cnt[1]) if (v == leaves[1]) ans++;

    // cout << leaves[1] << " a" << endl;
    

    cout << ans << "\n";

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        topics[i].clear();
        cnt[i].clear();
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
