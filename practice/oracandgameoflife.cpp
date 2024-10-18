#include <bits/stdc++.h>
using namespace std;


int n, m, t;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<string> grid;

const int MAX_N = 1010;
int col[MAX_N][MAX_N];
int when[MAX_N][MAX_N];


bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void mark(int x, int y, int cur) {
    col[x][y] = cur;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && grid[nx][ny] == grid[x][y] && col[nx][ny] == -1) mark(nx, ny, cur);
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t;
    grid.resize(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            col[i][j] = -1;
            when[i][j] = -1;
        }
    }
    
    for (int i = 0; i < n; i++) cin >> grid[i];
        
    int cur = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) if (col[x][y] == -1) mark(x, y, cur++);
    }

    queue<pair<int, int>> q;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            bool found = false;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (valid(nx, ny) && col[nx][ny] == col[x][y]) found = true;
            }

            if (found) {
                q.push({x, y});
                when[x][y] = 1;
            }
        }
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && when[nx][ny] == -1) {
                when[nx][ny] = when[x][y] + 1;
                q.push({nx, ny});
            }
        }
        q.pop();
    }
   
    while (t--) {
        int x, y;
        long long p;
        cin >> x >> y >> p;
        x--;
        y--;
        
        if (when[x][y] == -1 || p < when[x][y]) cout << grid[x][y] << "\n";
        else {
            int l = ((p - when[x][y] + 1) + (grid[x][y] - '0')) % 2;
            cout << l << "\n";
        }
    }
}
