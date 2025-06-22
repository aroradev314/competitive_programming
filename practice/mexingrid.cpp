#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int>> spiralFill(int n) {
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int x, y;

    if (n % 2 == 1) {
        x = y = n / 2;  // Center for odd n
    } else {
        x = n / 2 - 1;  // Top-right of the 4 center elements
        y = n / 2;
    }

    // Directions: right, down, left, up
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int dir = 0;  // start going right
    int steps = 1, count = 0;
    grid[x][y] = count++;

    while (count < n * n) {
        for (int i = 0; i < 2; ++i) {  // Repeat same step count twice
            for (int j = 0; j < steps; ++j) {
                x += dx[dir];
                y += dy[dir];

                if (x >= 0 && x < n && y >= 0 && y < n) {
                    grid[x][y] = count++;
                }
            }
            dir = (dir + 1) % 4;
        }
        ++steps;
    }

    return grid;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> ans = spiralFill(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
    	cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    