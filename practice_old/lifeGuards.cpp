// USACO 2018 January Silver P1
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> times(n);
	for (int i = 0; i < n; i++) {
		cin >> times[i].first >> times[i].second;
	}
	sort(times.begin(), times.end());
	int maxRight = -1, totalTime = 0;
	int minTime = INT_MAX;
	bool subset = false;
	for (int i = 0; i < n; i++) {
		if (times[i].second <= maxRight) {
			subset = true;
		}
		else {
			totalTime += times[i].second - max(times[i].first, maxRight);
		}
		int currentTime = times[i].second - times[i].first;
		if (i > 0) {
			currentTime -= max(maxRight - times[i].first, 0);
		}
		if (i < n - 1) {
			currentTime -= max(times[i].second - times[i + 1].first, 0);
		}
		minTime = min(minTime, currentTime);
		maxRight = max(maxRight, times[i].second);
	}
	int ans = totalTime;
	if (!subset) {
		ans -= max(minTime, 0);
	}
	cout << ans << endl;
}

	
	
	
