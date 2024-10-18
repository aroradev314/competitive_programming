#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<char>> directions(n + 2, vector<char>(n + 2));
	vector<vector<int>> price(n + 2, vector<int>(n + 2));
	for (int i = 1; i <= n; i++) {
		string l;
		cin >> l;
		for (int j = 1; j <= n; j++) {
			directions[i][j] = l[j - 1];
		}
		cin >> price[i][n + 1];
	}
	for (int i = 1; i <= n; i++) {
		cin >> price[n + 1][i];
	}
	
	vector<vector<int>> total(n + 2, vector<int>(n + 2));
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (i != n + 1 && j != n + 1) total[i][j] = 1;
			if (i > 1 && directions[i - 1][j] == 'D') total[i][j] += total[i - 1][j];
			if (j > 1 && directions[i][j - 1] == 'R') total[i][j] += total[i][j - 1];
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += total[i][n + 1] * price[i][n + 1];
		ans += total[n + 1][i] * price[n + 1][i];
	}
	
	int q;
	cin >> q;
	cout << ans << "\n";
	while (q--) {
		int x, y;
		cin >> x >> y;
		
		int cur = total[x][y];
		int cur_x = x, cur_y = y;
		while (cur_x != n + 1 && cur_y != n + 1) {
			total[cur_x][cur_y] -= cur;
			if (directions[cur_x][cur_y] == 'R') cur_y++;
			else cur_x++;
		}
		ans -= cur * price[cur_x][cur_y];
		
		cur_x = x;
		cur_y = y;
		if (directions[cur_x][cur_y] == 'R') directions[cur_x][cur_y] = 'D';
		else directions[cur_x][cur_y] = 'R';
		while (cur_x != n + 1 && cur_y != n + 1) {
			total[cur_x][cur_y] += cur;
			if (directions[cur_x][cur_y] == 'R') cur_y++;
			else cur_x++;
		}
		ans += cur * price[cur_x][cur_y];
		
		cout << ans << "\n";
	}
}
		
	
	
	
	
	
