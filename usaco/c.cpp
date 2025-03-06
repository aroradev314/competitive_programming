#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
char grid[MAX_N + 10][MAX_N + 10];
bool usable[MAX_N + 10][MAX_N + 10];
int first[MAX_N + 10][MAX_N + 10][2];

int n, q;
int ans;

bool found;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
	return (x >= 1 && y >= 1 && x <= n && y <= n);
}

int dir(char c) {
	if (c == 'D') return 0;
	else if (c == 'U') return 1;
	else if (c == 'R') return 2;
	else return 3;
}

char opp(char c) {
	if (c == 'D') return 'U';
	else if (c == 'U') return 'D';
	else if (c == 'R') return 'L';
	else return 'R';
}

void dfs(int x, int y) {
	usable[x][y] = false;
	ans++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!valid(nx, ny) || grid[nx][ny] == '?' || !usable[nx][ny]) continue;
		int pdir = dir(grid[nx][ny]);
		int px = nx + dx[pdir];
		int py = ny + dy[pdir];

		if (px == nx && py == ny) dfs(nx, ny);
	}
}

void dfs_question(int x, int y) {
	grid[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!valid(nx, ny) || (grid[nx][ny] != '?' && usable[nx][ny])) {
			found = true;
		}
		if (grid[nx][ny] == '?') dfs_question(nx, ny);
	}
	grid[x][y] = '?';
	if (!found) {
		usable[x][y] = false;
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			grid[i][j] = '?';
			first[i][j][0] = i;
			first[i][j][1] = j;
			usable[i][j] = true;
		}
	}

	ans = 0;
	while (q--) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		grid[x][y] = c;

		if (!usable[x][y]) {
			cout << ans << "\n";
			continue;
		}

		int direction = dir(c);
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (!valid(nx, ny)) {
			first[x][y][0] = nx;
			first[x][y][1] = ny;
		}
		else if (usable[nx][ny]) {
			// we have created a new cycle
			if (first[nx][ny][0] == x && first[nx][ny][1] == y) {
				int cx = nx, cy = ny;
				while (!(cx == x && cy == y)) {
					usable[cx][cy] = false;
					ans++;
					int cdir = dir(grid[cx][cy]);
					cx += dx[cdir];
					cy += dy[cdir];
				}
				dfs(x, y);
			}
			else {
				first[x][y][0] = first[nx][ny][0];
				first[x][y][1] = first[nx][ny][1];
			}
		}
		else {
			dfs(x, y);
		} 

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				found = false;
				if (grid[i][j] == '?' && usable[i][j]) dfs_question(i, j);
			}
		}


		/*
		if (ans == 1) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) cout << (usable[i][j] ? "1 " : "0 ");
				cout << endl;
			}
		}
		*/

		cout << ans << "\n";
	}
}


