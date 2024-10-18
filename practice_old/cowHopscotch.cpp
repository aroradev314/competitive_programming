// USACO Silver 2015 February 
// P2

#include <vector>
#include <iostream>
using namespace std;

int MOD = 1000000007;

int main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<int>> board(r, vector<int>(c));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	
	vector<vector<int>> dp(r, vector<int>(c));
	dp[0][0] = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int x = 0; x < i; x++) {
				for (int y = 0; y < j; y++) {
					if (board[i][j] != board[x][y]) {
						dp[i][j] += dp[x][y];
						dp[i][j] %= MOD;
					}
				}
			}
		}
	}
	
	cout << dp[r - 1][c - 1] << endl;
}
	
	
	
