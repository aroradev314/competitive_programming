#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dir(char c) {
	if (c == 'U') return 0;
	else if (c == 'D') return 1;
	else if (c == 'R') return 2;
	else return 3; 
}

bool valid(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int x, int y, vector<vector<int>>& visited, vector<string>& grid) {
	visited[x][y] = 3;

	if (grid[x][y] == '?') {
		visited[x][y] = 2;
		return;
	}

	int nx = x + dx[dir(grid[x][y])], ny = y + dy[dir(grid[x][y])];
	if (!valid(nx, ny)) {
		visited[x][y] = 1;
		return;
	}
	else if (visited[nx][ny] == 3) {
		visited[x][y] = 2;
		return;
	}
	else if (visited[nx][ny]) visited[x][y] = visited[nx][ny];
	else dfs(nx, ny, visited, grid);

	visited[x][y] = visited[nx][ny];
}

void solve() {
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> visited(n, vector<int>(m)); // 0 - not visited, 1 - visited and leads outside, 2 - visited and is in cycle, 3 - still under review

    for (int i = 0; i < n; i++) cin >> grid[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (visited[i][j] || grid[i][j] == '?') continue;
    		dfs(i, j, visited, grid);
    	}
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (visited[i][j]) continue;
    		bool found = false;
    		for (int k = 0; k < 4; k++) {
    			int nx = i + dx[k], ny = j + dy[k];
    			if (!valid(nx, ny)) continue;
    			if (visited[nx][ny] == 2 || grid[nx][ny] == '?') found = true;
    		}
    		visited[i][j] = (found ? 2 : 1);
    	}
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (visited[i][j] == 2) ans++;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    