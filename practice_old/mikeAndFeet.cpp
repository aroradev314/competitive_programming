#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	vector<int> left(n + 1), maxVal(n + 1);
	stack<pair<int, int>> current;
	current.push({0, 0});
	
	for (int i = 1; i <= n; i++) {
		while (current.top().first >= nums[i]) {
			current.pop();
		}
		left[i] = current.top().second + 1;
		current.push({nums[i], i});
	}
	while (current.size() > 0) {
		current.pop();
	}
	current.push({0, n + 1});
	for (int i = n; i >= 1; i--) {
		while (current.top().first >= nums[i]) {
			current.pop();
		}
		int len = (current.top().second - 1) - left[i] + 1;
		maxVal[len] = max(maxVal[len], nums[i]);
		current.push({nums[i], i});
	}
	int mx = maxVal[n];
	for (int i = n - 1; i >= 0; i--) {
		mx = max(mx, maxVal[i]);
		maxVal[i] = mx;
	}
	for (int i = 1; i <= n; i++) {
		cout << maxVal[i] << " ";
	}
}

	
	
	
