// USACO 2021 Jan Silver P1
#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> left(k), right(k);
	for (int i = 0; i < k; i++) {
		cin >> left[i] >> right[i];
		left[i]--;
		right[i]--;
	}
	vector<int> cows(n);
	iota(cows.begin(), cows.end(), 0);
	vector<set<int>> pos(n);
	for (int i = 0; i < n; i++) {
		pos[i].insert(i);
	}
	
	for (int i = 0; i < k; i++) {
		swap(cows[left[i]], cows[right[i]]);
		pos[cows[right[i]]].insert(right[i]);
		pos[cows[left[i]]].insert(left[i]);
	}
	
	vector<int> shift(n);
	for (int i = 0; i < n; i++) {
		shift[cows[i]] = i;
	}
	
	vector<bool> visited(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		int current = shift[i];
		set<int> possible(pos[i].begin(), pos[i].end());
		while (current != i) {
			possible.insert(pos[current].begin(), pos[current].end());
			visited[current] = true;
			current = shift[current];
		}
		int total = possible.size();
		ans[current] = total;
		current = shift[current];
		while (current != i) {
			ans[current] = total;
			current = shift[current];
		}
	}
	for (int i : ans) {
		cout << i << endl;
	}
}
