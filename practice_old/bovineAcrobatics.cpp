#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<long long, long long>> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end());
	
	long long total = 0;
	map<long long, long long, greater<long long>> cur;
	
	for (int i = n - 1; i >= 0; i--) {
		long long rep = 0;
		if (m > 0) {
			int begin = min(cows[i].second, m);
			rep += begin;
			cows[i].second -= begin;
			m -= begin;
		}
		
		vector<int> remove;
		for (auto& p : cur) {
			if (cows[i].second == 0 || p.first - cows[i].first < k) break;
			if (cows[i].first == 9) cout << "YES";
			
			int add = min(p.second, cows[i].second);
			rep += add;
			p.second -= add;
			cows[i].second -= add;
			
			if (p.second == 0) remove.push_back(p.first);
		}
		
		for (int j : remove) {
			cur.erase(j);
		}
		
		if (rep != 0) cur[cows[i].first] = rep;
		total += rep;
	}
	
	cout << total;
}
		
		
		
			
			
			
	
	
