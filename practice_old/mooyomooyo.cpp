// USACO 2018 December P3
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
int total;

void dfs(vector<vector<bool>>& visited, vector<string>& board, int i, int j, int n) {
	total++;
	visited[i][j] = true;
	for (int dir = 0; dir < 4; dir++) {
		int newI = i + di[dir];
		int newJ = j + dj[dir];
		if (newI >= 0 && newI < n && newJ >= 0 && newJ < 10 && !visited[newI][newJ] && board[newI][newJ] == board[i][j]) {
			dfs(visited, board, newI, newJ, n);
		}
	}
}

bool removeConnected(vector<string>& board, int k, int n) {
	vector<vector<bool>> visited(n, vector<bool>(10));
	bool changed = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (!visited[i][j] && board[i][j] != '0') {
				vector<vector<bool>> curVisited(n, vector<bool>(10));
				total = 0;
				dfs(curVisited, board, i, j, n);
				if (total >= k) {
					changed = true;
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < 10; y++) {
							if (curVisited[x][y]) {
								curVisited[x][y] = false;
								visited[x][y] = true;
								board[x][y] = '0';
							}
						}
					}
				}
			}
		}
	}
	return changed;
}						

void removeZeros(vector<string>& board, int n) {
	for (int j = 0; j < 10; j++) {
		int lastZero = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			while (lastZero > i && board[lastZero][j] != '0') {
				lastZero--;
			}
			if (board[i][j] != '0') {
				char temp = board[i][j];
				board[i][j] = '0';
				board[lastZero][j] = temp;
			}
		}
	}
}
			
int main() {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<string> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	bool changed = true;
	while (changed) {
		changed = removeConnected(board, k, n);
		removeZeros(board, n);
	}
	for (string i : board) {
		cout << i << endl;
	}
}

