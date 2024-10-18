#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	vector<int> l = {-1};

	int ans = 0;
	for (int i : nums) {
		auto before = lower_bound(l.begin(), l.end(), i);
		int ind = distance(l.begin(), before) - 1;
		if (ind == l.size() - 1) {
			ans = l.size();
			l.push_back(i);
		}
		else {
			l[ind + 1] = min(l[ind + 1], i);
		}
	}
	return ans;
}

int main() {
	vector<int> nums = {7,7,7,7,7,7,7};
	
	cout << lengthOfLIS(nums);
}
