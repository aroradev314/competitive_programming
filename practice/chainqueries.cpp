#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> col;

void dfs(int u, int p, vector<vector<int>>& adj) {

}

void solve() {
    int n, q;
    cin >> n >> q;
    col.assign(n);
    for (int i = 0; i < n; i++) cin >> col[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b, a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    } 


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    