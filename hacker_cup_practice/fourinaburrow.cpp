#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

map<array<int, 7>, int> dp; // -1 if nobody won, 0 if C won, 1 if F won, and 2 if unknown
const int ROWS = 6;
const int COLS = 7;
vector<string> grid(ROWS);

int winner(array<int, 7>& cur) {
	int seen, last;
	for (int i = 0; i < ROWS; i++) {
		seen = 0, last = -1;
		for (int j = 0; j < COLS; j++) {
			if (i >= 6 - cur[j]) 
				if (j > 0 && grid[i][j] == grid[i][j - 1] && i >= 6 - cur[j - 1]) seen++;
				else {
					seen = 1;
					last = (grid[i][j] == 'C' ? 0 : 1);
				}
			}
			// if (seen == 4 && i == 5) cout << i << " " << j << " HORIZONTAL\n";
			if (seen == 4) return last;
		}
	}
	for (int j = 0; j < COLS; j++) {
		seen = 0, last = -1;
		for (int i = 0; i < ROWS; i++) {
			if (i >= 6 - cur[j]) {
				if (i > 0 && grid[i][j] == grid[i - 1][j] && i - 1 >= 6 - cur[j]) seen++;
				else {
					seen = 1;
					last = (grid[i][j] == 'C' ? 0 : 1);
				}
			}
			if (seen == 4) return last;
		}
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (i >= 6 - cur[j]) {
				array<int, 4> valid;
				for (int a = 0; a < 4; a++) valid[a] = (grid[i][j] == 'C' ? 0 : 1);
				for (int k = 1; k < 4; k++) {
					if (!(i + k < ROWS && j + k < COLS && grid[i + k][j + k] == grid[i][j] && i + k >= 6 - cur[j + k])) valid[0] = -1;
					if (!(i + k < ROWS && j - k >= 0 && grid[i + k][j - k] == grid[i][j] && i + k >= 6 - cur[j - k])) valid[1] = -1;
					if (!(i - k >= 0 && j + k < COLS && grid[i - k][j + k] == grid[i][j] && i - k >= 6 - cur[j + k])) valid[2] = -1;
					if (!(i - k >= 0 && j - k >= 0 && grid[i - k][j - k] == grid[i][j] && i - k >= 6 - cur[j - k])) valid[3] = -1;
				}
				for (int a = 0; a < 4; a++) if (valid[a] != -1) {
					// cout << i << " " << j << " DIAGONAL\n";
					return valid[a];
				}
			}
		}
	}
	return -1;
}

void find_ans(array<int, 7>& cur) {
	int sm = 0;
	for (int i = 0; i < 7; i++) sm += cur[i];
	if (sm == 0) {
		dp[cur] = -1;
		return;
	}
	int c = 0, f = 0, unknown = 0, none = 0;
	if (sm % 2) { // Connie just played 
		for (int col = 0; col < COLS; col++) {
			if (cur[col] > 0 && grid[6 - cur[col]][col] == 'C') {
				cur[col]--;
				
				if (!dp.count(cur)) find_ans(cur);
				if (dp[cur] == 0) c++;
				else if (dp[cur] == 1) f++;
				else if (dp[cur] == 2) unknown++;
				else if (dp[cur] == -1) none++;

				cur[col]++;
			}
		}
	}
	else {
		for (int col = 0; col < COLS; col++) {
			if (cur[col] > 0 && grid[6 - cur[col]][col] == 'F') {
				cur[col]--;
				if (!dp.count(cur)) find_ans(cur);

				if (dp[cur] == 0) c++;
				else if (dp[cur] == 1) f++;
				else if (dp[cur] == 2) unknown++;
				else if (dp[cur] == -1) none++;

				cur[col]++;
			}
		}
	}

	if (c == 0 && f == 0 && unknown == 0 && none == 0) {
		dp[cur] = 3;
		return;
	}

	dp[cur] = -1;
	if ((c > 0 && f > 0) || unknown > 0) dp[cur] = 2;
	else if (c > 0) dp[cur] = 0;
	else if (f > 0) dp[cur] = 1;
	else dp[cur] = winner(cur);
}

void solve() {
	dp.clear();
    for (int i = 0; i < ROWS; i++) cin >> grid[i];


    array<int, 7> start;
	for (int i = 0; i < 7; i++) start[i] = 6;
	// cout << winner(start) << endl;
	find_ans(start);

	if (dp[start] == 0) cout << "C\n";
	else if (dp[start] == 1) cout << "F\n";
	else if (dp[start] == 2) cout << "?\n";
	else cout << "0\n";
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
    