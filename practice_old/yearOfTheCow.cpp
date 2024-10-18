#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> years(n);
	for (int i = 0; i < n; i++) {
		cin >> years[i];
	}
	auto cmp = [](int a, int b) { return a > b; };
	set<int, decltype(cmp)> segments(cmp);
	int total = 0;
	for (int year : years) {
		int s = ((year / 12) + 1) * 12;
		total = max(total, s);
		segments.insert(s);
	}
	segments.insert(0);
	vector<int> times;
	for (auto itr = segments.begin(); itr != prev(segments.end()); itr++) {
		int current = *itr;
		int nxt = *(next(itr));
		times.push_back((current - 12) - nxt);
	}
	sort(times.begin(), times.end());
	int reduce = min(k - 1, (int) times.size());
	for (int i = 0; i < reduce; i++) {
		total -= times[times.size() - 1 - i];
	}
	cout << total << endl;
}
	
	
		
	
	
	
	
	
	
