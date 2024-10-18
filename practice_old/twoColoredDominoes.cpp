#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	
	vector<string> ans(n, string(m, '.'));
	
	vector<int> diff_rows(n), diff_cols(m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'U') {
				if (diff_rows[i] >= 0) {
					ans[i][j] = 'W';
					ans[i + 1][j] = 'B';
					diff_rows[i]--;
					diff_rows[i + 1]++;
				}
				else {
					ans[i][j] = 'B';
					ans[i + 1][j] = 'W';
					diff_rows[i]++;
					diff_rows[i + 1]--;
				}
			}
		}
	}
	
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j] == 'L') {
				if (diff_cols[j] >= 0) {
					ans[i][j] = 'W';
					ans[i][j + 1] = 'B';
					diff_cols[j]--;
					diff_cols[j + 1]++;
				}
				else {
					ans[i][j] = 'B';
					ans[i][j + 1] = 'W';
					diff_cols[j]++;
					diff_cols[j + 1]--;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (diff_rows[i] != 0) {
			cout << -1 << "\n";
			return;
		}
	}
	for (int i = 0; i < m; i++) {
		if (diff_cols[i] != 0) {
			cout << -1 << "\n";
			return;
		}
	}
	
	for (string i : ans) {
		cout << i << "\n";
	}
	
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

