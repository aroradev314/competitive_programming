#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 17;
bool adj[MAX_N][MAX_N];
int cost[1 << MAX_N];
int dp[1 << MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a][b] = true;
		adj[b][a] = true;
	}

	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < n; j++) 
	// 		adj[i][j] = !adj[i][j];

	// for each subset, count ops to remove every edge inside it
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (((1 << j) & i) && ((1 << k) & i)) {
					if (adj[j][k]) {
						cost[i]++;
					}
				}
				else if (((1 << j) & i)) {
					if (!adj[j][k]) {
						cost[i]++;
					}
				}
			}
		}
	}

	// what should dp[i] store
	// 
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = cost[i];
		for (int mask = i; mask != 0; mask = (mask - 1) & i) {
			int s = i ^ mask;
			if (s == 0) continue;
			dp[i] = min(dp[i], dp[i ^ s] + cost[s]);
		}
	}

	cout << dp[(1 << n) - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    