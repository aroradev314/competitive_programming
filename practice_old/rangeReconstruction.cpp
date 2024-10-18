#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> range(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin >> range[i][j];
		}
	}
	
	vector<int> ans(n + 1);
	vector<vector<int>> mx(n + 1, vector<int>(n + 1)), mn(n + 1, vector<int>(n + 1));
	for (int i = 2; i <= n; i++) {
		ans[i] = ans[i - 1] + range[i - 1][i];
		
		for (int j = i - 2; j >= 1; j--) {
			if (max(mx[j][i], ans[i]) - min(mn[j][i], ans[i]) != range[j][i]) {
				ans[i] = ans[i - 1] - range[i - 1][i];
				break;
			}
		}
		
		for (int j = 1; j <= i; j++) {
			mx[j][i] = max(mx[j][i], ans[i]);
			mn[j][i] = min(mn[j][i], ans[i]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}

		
		
		
