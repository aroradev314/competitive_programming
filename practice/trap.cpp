#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;
	
const int MAX_N = 1e5 + 10;
vector<int> adj[MAX_N];
int d[MAX_N];

void dfs(int u, int p, int c) {
	d[u] = c;
	for (int v : adj[u]) if (v != p) dfs(v, u, c + 1);
}

void solve() {
    int n, s, e;
    cin >> n >> s >> e;
    s--, e--;

    for (int i = 0; i < n - 1; i++) {
    	int x, y;
    	cin >> x >> y, x--, y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    dfs(e, -1, 0);

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    sort(perm.begin(), perm.end(), [&](int x, int y) {
    	return d[x] > d[y];
    });

    for (int i : perm) cout << i + 1 << " ";
    cout << "\n";

	for (int i = 0; i < n; i++) adj[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    