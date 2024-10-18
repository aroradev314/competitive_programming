// USACO 2020 December Silver P1
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end());
	
	set<int> y;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		y.clear();
		for (int j = i; j < n; j++) {
			y.insert(cows[j].second);
			int maxY = max(cows[i].second, cows[j].second);
			int minY = min(cows[i].second, cows[j].second);
			
			long long lower = distance(y.begin(), lower_bound(y.begin(), y.end(), minY)) + 1;
			long long higher = distance(lower_bound(y.begin(), y.end(), maxY), y.end());
			ans += lower * higher;
		}
	}
	cout << ans + 1 << endl;
}
			
			
	
