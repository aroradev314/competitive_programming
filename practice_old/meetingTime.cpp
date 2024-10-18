// USACO Silver 2015 January 
// P3

#include <vector>
#include <iostream>
using namespace std;

vector<bool> solve(vector<vector<int>> adj, int n) {
	vector<vector<bool>> dp(n, vector<bool>(100 * n + 1));
	
	dp[0][0] = true;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int) dp[i].size(); j++) {
			if (dp[i][j]) {
				for (int k = i + 1; k < n; k++) {
					if (adj[i][k] > 0) {
						dp[k][j + adj[i][k]] = true;
					}
				}
			}
		}
	}
	return dp[n - 1];
}


int main() {
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> bessieAdj(n, vector<int>(n)), elsieAdj(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		cin >> bessieAdj[a][b];
		cin >> elsieAdj[a][b];
	}
	
	vector<bool> bessieCan = solve(bessieAdj, n);
	vector<bool> elsieCan = solve(elsieAdj, n);
	
	int ans = -1;
	for (int i = 0; i <= 100 * n; i++) {
		if (bessieCan[i] && elsieCan[i]) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans << endl;
	}
	
}



	
	

	
