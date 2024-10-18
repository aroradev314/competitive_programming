#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std;

vector<vector<int>> ans;
int n;

void check(vector<vector<int>> cur, vector<vector<string>>& dir) {
    bool filled = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cur[i][j] == 0 || dir[i][j] == "XX") {
                filled = false;
                continue;
            }

        }
    }
    if (filled) {
        ans = cur;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;

    vector<vector<string>> directions(n, vector<string>(n));
    vector<vector<int>> nums(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string inp;
            cin >> inp;

            directions[i][j] = inp.substr(2, 2);
            nums[i][j] = stoi(inp.substr(0, 2));
        }
    }


    
}