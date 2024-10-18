// USACO 2020 Feb P2
#include <iostream>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> nums(n);
	iota(nums.begin(), nums.end(), 0);
	vector<int> l(n), r(n);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}
	
	for (int i = 0; i < m; i++) {
		reverse(nums.begin() + l[i], nums.begin() + r[i] + 1);
	}
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[nums[i]] = i;
	}
	
	vector<bool> visited(n);
	
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		
		visited[i] = true;
		vector<int> cycle;
		cycle.push_back(i);
		int current = pos[i];
		while (current != i) {
			cycle.push_back(current);
			visited[current] = true;
			current = pos[current];
		}
		
		int total = cycle.size();
		int steps = k % total;
		for (int j = 0; j < total; j++) {
			int next = (j + steps) % total;
			nums[cycle[next]] = cycle[j];
		}
	}
	for (int i : nums) {
		cout << i + 1 << endl;
	}
}

	
