// #include <vector>
// #include <iostream>
// #include <limits.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> xs(n), ys(n);
	for (int i = 0; i < n; i++) {
		cin >> xs[i].first >> xs[i].second;
		ys[i].first = xs[i].first;
		ys[i].second = xs[i].second;
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
	
	
	int currentX = 0;
	int ans = INT_MAX;
	while (currentX < n) {
		while (currentX < n - 1 && xs[currentX].first == xs[currentX + 1].first) {
			currentX++;
		}
		int topLeft = currentX + 1;
		int topRight = n - topLeft;
		int bottomLeft = 0, bottomRight = 0;
		
		int currentY = 0;
		while (currentY < n) {
			while (currentY < n - 1 && ys[currentY].second == ys[currentY + 1].second) {
				if (ys[currentY].first < xs[currentX].first + 1) {
					bottomLeft++;
					topLeft--;
				}
				else {
					bottomRight++;
					topRight--;
				}
				currentY++;
			}
			if (ys[currentY].first < xs[currentX].first + 1) {
				bottomLeft++;
				topLeft--;
			}
			else {
				bottomRight++;
				topRight--;
			}
			int maxM = max(bottomLeft, max(bottomRight, max(topLeft, topRight)));
			ans = min(ans, maxM);
			currentY++;
		}
		currentX++;
	}
	cout << ans << endl;
}
			
			
		
		
