#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n);
   	for (int i = 0; i < n; i++) cin >> b[i];

   	vector<vector<pair<int, int>>> adj(n);
   	for (int i = 0; i < m; i++) {
   		int s, t, w;
   		cin >> s >> t >> w, s--, t--;
   		adj[s].push_back({t, w});
   	}

   	int l = 1, r = INF;
   	while (l <= r) {
   		int mid = l + (r - l) / 2;
   		vector<int> dp(n, -1);
   		dp[0] = 0;

   		for (int i = 0; i < n; i++) {
   			if (dp[i] == -1) continue;
   			dp[i] += b[i];
   			dp[i] = min(dp[i], mid);

   			for (auto [t, w] : adj[i]) {
   				if (dp[i] >= w) dp[t] = max(dp[t], dp[i]);
   			}
   		}

   		if (dp[n - 1] != -1) r = mid - 1;
   		else l = mid + 1;
   	}

   	if (r == INF) cout << "-1\n";
   	else cout << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    