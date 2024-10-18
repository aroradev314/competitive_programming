// // USACO 2017 December P2
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int n, g;
	cin >> n >> g;
	vector<vector<int>> measurements(n);
	
	multiset<int> maxCow;
	map<int, int> cowVal;
	
	for (int i = 0; i < n; i++) {
		int time, id, change;
		cin >> time >> id >> change;
		measurements[i] = {time, id, change};
		maxCow.insert(g);
		cowVal[id] = g;
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(measurements.begin(), measurements.end());
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		int id = measurements[i][1], change = measurements[i][2];
		int currentVal = cowVal[id];
		int first = *(prev(maxCow.end(), 1));
		int second = *(prev(maxCow.end(), 2));
		if ((currentVal == first && currentVal + change <= second) || (currentVal == first && first == second && change > 0) || (currentVal < first && currentVal + change >= first)) {
			total++;
		}
		auto currentIt = maxCow.find(currentVal);
		maxCow.erase(currentIt);
		cowVal[id] = currentVal + change;
		maxCow.insert(currentVal + change);
	}
	cout << total << endl;
}
		
	
