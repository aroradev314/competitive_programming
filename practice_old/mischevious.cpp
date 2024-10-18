// G FINISH IT
#include <iostream>
#include <vector>
using namespace std;

void test_case() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> target(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> target[i];
		target[i] = '.' + target[i] + '.';
	}
	for (int i = 0; i <= m + 1; i++) {
		target[0] += '.';
	}
	
	
	vector<vector<int>> vert(n + 2, vector<int>(m + 2)), diag_r(n + 2, vector<int>(m + 2)), diag_l(n + 2, vector<int>(m + 2));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vert[i][j] = diag_r[i][j] = diag_l[i][j] = int(target[i][j] == '#');
			vert[i][j] += vert[i - 1][j];
			diag_r[i][j] += diag_r[i - 1][j - 1];
			diag_l[i][j] += diag_l[i - 1][j + 1];
		}
	}
	
	
	int ans = 0;
	
	// left_down
	int start_row = k, start_col = 1;
	int start = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (abs(start_row - i) + abs(start_col - j) <= k) {
				start += int(target[i][j] == '#');
			}
		}
	}
	
	for (int row = k + 1; row <= m - k; row++) {
		start
	
	cout << start << endl;
}
		
	
		


int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

