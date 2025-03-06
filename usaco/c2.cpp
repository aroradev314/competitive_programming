#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
char grid[MAX_N + 10][MAX_N + 10];
bool usable[MAX_N + 10][MAX_N + 10];
int visited[MAX_N + 10][MAX_N + 10]; // 0 means usable, 2 means not usable

int n, q;
int ans;
bool works;

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
	
}


int main() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			grid[i][j] = '?';
		}
	}

	ans = 0;

	while (q--) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		grid[x][y] = c;


