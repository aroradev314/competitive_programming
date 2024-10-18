/*
 * Codeforces Round 854 by cybercats (Div. 1 + Div. 2)
 * Question B
*/ 

// i dont understand why it isnt passing the test case

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	if (nums[0] == nums[n - 1]) {
		cout << 0 << endl;
		return;
	}
	if (nums[0] == 1) {
		cout << -1 << endl;
		return;
	}
	vector<pair<int, int>> operations;
	int maxVal, minVal, maxValInd, minValInd;
	while (true) {
		maxVal = INT_MIN;
		minVal = INT_MAX;
		maxValInd = -1;
		minValInd = -1;
		for (int i = 0; i < n; i++) {
			if (nums[i] > maxVal) {
				maxVal = nums[i];
				maxValInd = i;
			}
			if (nums[i] < minVal) {
				minVal = nums[i];
				minValInd = i;
			}
		}
		if (maxVal == minVal) {
			break;
		}
		nums[maxValInd] = int(ceil(double(maxVal) / double(minVal)));
		operations.push_back(make_pair(minValInd + 1, maxValInd + 1));
	}
	cout << operations.size() << endl;
	for (pair<int, int> i : operations) {
		cout << i.first << " " << i.second << endl;
	}
}			

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
