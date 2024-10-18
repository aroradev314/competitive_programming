// USACO 2018 US Open P1
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> nums(n), sorted(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sorted[i] = nums[i];
	}
	sort(sorted.begin(), sorted.end());
	map<int, queue<int>> lastSeen;
	int maxDiff = 0;
	for (int i = 0; i < n; i++) {
		if (lastSeen.count(sorted[i])) {
			lastSeen[sorted[i]].push(i);
		}
		else {
			lastSeen[sorted[i]] = queue<int>({i});
		}
		if (lastSeen.count(nums[i])) {
			int first = lastSeen[nums[i]].front();
			lastSeen[nums[i]].pop();
			maxDiff = max(maxDiff, i - first);
		}
	}
	cout << maxDiff + 1 << endl;
}
			
	
	
	
	
