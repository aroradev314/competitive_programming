#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std;

int n;
vector<int> ans;
bool found = false;

void dfs(vector<vector<int> >& nums, int row, vector<int> mask, vector<int>& col_sum, vector<int>& row_sum) {
    if (found) return;
    if (row == n) {
        bool works = true;
        // for (int i : mask) {
        //     cout << i << endl;
        // }
        // cout << endl;
        for (int col = 0; col < n; col++) {
            int sum = 0;
            for (int row = 0; row < n; row++) {
                if (mask[row] & (1 << (col))) {
                    sum += nums[row][col];
                }
            }
            if (sum != col_sum[col]) {
                works = false;
                break;
            }
        }
        if (works) {
            found = true;
        }
        return;
    }

    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += nums[row][j];
        }
        if (sum != row_sum[row]) continue;
        if (row == 0) cout << i << endl;
        mask.push_back(i);
        dfs(nums, row + 1, mask, col_sum, row_sum);
        mask.pop_back();
    }
    return;
}

int main() {
    freopen("input.txt", "r", stdin);   

    cin >> n;
    cout << n << endl;

    vector<int> col_sum(n), row_sum(n);
    vector<vector<int> > packs(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> col_sum[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> row_sum[i];
        for (int j = 0; j < n; j++) {
            cin >> packs[i][j];
        }
    }
    ans.resize(n);

    vector<int> mask;
    dfs(packs, 0, mask, col_sum, row_sum);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i] & (1 << j)) cout << packs[i][j] << " ";
            else cout << ". ";
        }
        cout << "\n";    
    }
}