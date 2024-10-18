#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector<string> forest(n);
	for (int i = 0; i < n; i++) {
		cin >> forest[i];
	}
	
	vector<vector<int>> pref(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + int(forest[i - 1][j - 1] == '*');
		}
	}
	
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int ans = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
		
		cout << ans << endl;
	}
}

