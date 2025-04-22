#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++) cin >> d[i], d[i]--;

    vector<bool> vis(n);
	int ans = 0;
    for (int i = 0; i < n; i++) {
    	int u = d[i];
    	while (!vis[u]) {
    		ans++;
    		vis[u] = true;
    		u = p[u];
    	}
    	cout << ans << " ";
    } 
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    