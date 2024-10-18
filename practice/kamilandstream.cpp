#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 1e5 + 10;
const int MOD = 1e9 + 7;
ll x[MAX_N];
vector<int> adj[MAX_N];
map<ll, int> m[MAX_N];

ll ans = 0;

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}


ll hgcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    else return gcd(a, b);
}

void dfs(int u, int p) {
    if (u != 1) {
        for (auto& [j, cnt] : m[p]) {
            m[u][hgcd(x[u], j)] = cnt;
        }
    }
    m[u][x[u]]++;

    for (auto& [j, cnt] : m[u]) ans = add(ans, mul(j, cnt));

    for (int v : adj[u]) if (v != p) dfs(v, u);
}

int32_t main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> x[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1);

    cout << ans;
}
