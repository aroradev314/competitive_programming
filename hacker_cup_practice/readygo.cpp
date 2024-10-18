#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 3000;
int r, c;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

char board[MAX_N + 10][MAX_N + 10];
int cnt[MAX_N + 10][MAX_N + 10];
bool visited[MAX_N + 10][MAX_N + 10];

bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < c; j++) {
            board[i][j] = s[j];
            cnt[i][j] = 0;
            visited[i][j] = false;
        }
    }

    stack<pair<int, int>> s;
    set<pair<int, int>> cur;
    
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && board[i][j] == 'W') {
                s.push({i, j});
                visited[i][j] = true;
                cur.clear();
                int seen = 0;
                while (!s.empty()) {
                    auto [x, y] = s.top();
                    s.pop();
                    seen++;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (valid(nx, ny)) {
                            if (board[nx][ny] == 'W' && !visited[nx][ny]) {
                                s.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                            else if (board[nx][ny] == '.') cur.insert({nx, ny});
                        }
                    }
                }
                
                if (sz(cur) == 1) {
                    auto [x, y] = *cur.begin();
                    cnt[x][y] += seen;
                    ans = max(ans, cnt[x][y]);
                }
            }
        }
    }
    
    cout << (ans > 0 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
