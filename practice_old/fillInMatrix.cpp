#include <vector>
#include <iostream>

using namespace std;

int mex(vector<vector<int>>& mat, int n, int m) {
    vector<bool> fin(m + 5);
    for (int j = 0; j < m; j++) {
        vector<bool> s(m + 5, false);
        for (int i = 0; i < n; i++) {
            s[mat[i][j]] = true;
        }
        for (int i = 0; i < m + 5; i++) {
            if (!s[i]) {
                fin[i] = true;
                break;
            }
        }
    }
    for (int i = 0; i < m + 5; i++) {
        if (!fin[i]) {
            return i;
        }
    }
    return -1;
}

void test_case() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) {
            cout << 0 << endl;
        }
        return;
    }
   
    vector<vector<int>> mat(n, vector<int>(m));
   
    for (int i = 0; i < min(n, m - 1); i++) {
        mat[i][0] = i + 1;
    }
    for (int i = 0; i < min(n, m - 1); i++) {
        for (int j = 1; j < m; j++) {
            mat[i][j] = mat[i][j - 1] + 1;
            if (mat[i][j] > m - 1) {
                mat[i][j] = 0;
            }
        }
    }
    for (int i = min(n, m - 1); i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = mat[i - 1][j];
        }
    }
    cout << mex(mat, n, m) << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
}
