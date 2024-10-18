#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> pos(n);
	for (int i = 0; i < n; i++) { cin >> pos[i]; }
	sort(pos.begin(), pos.end());
	int maxAmount = max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1));
	
	int minAmount = 2e9;
	if (pos[n - 2] - pos[0] == n - 2 && pos[n - 1] - pos[n - 2] > 2) { minAmount = 2; }
	if (pos[n - 1] - pos[1] == n - 2 && pos[1] - pos[0] > 2) { minAmount = 2; }
	if (minAmount == 2) {
		cout << minAmount << endl << maxAmount << endl;
		return 0;
	}
	
	int l, r = 0, best = 0;
	for (l = 0; l < n; l++) {
		while (r < n - 1 && pos[r + 1] - pos[l] <= n - 1) {
			r++;
		}
		best = max(best, r - l + 1);
	}
	minAmount = n - best;	
	cout << minAmount << endl << maxAmount << endl;
}
	
	
	
			
