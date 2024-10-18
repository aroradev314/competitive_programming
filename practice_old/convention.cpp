// USACO 2018 December P1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> times(n);
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}
	sort(times.begin(), times.end());
	
	int l = 0, r = times[n - 1] - times[0];
	int ans = r + 1;
	while (l <= r) {
		int middle = l + (r - l) / 2;
		int current = 0, buses = 0;
		while (current < n) {
			int busMax = current + c;
			auto next = upper_bound(times.begin(), times.end(), times[current] + middle);
			current = min(busMax, (int) distance(times.begin(), next));
			buses++;
		}
		if (buses <= m) {
			ans = middle;
			r = middle - 1;
		}
		else {
			l = middle + 1;
		}
	}
	cout << ans << endl;
}
