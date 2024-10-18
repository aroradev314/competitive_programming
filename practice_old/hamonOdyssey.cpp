#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> nums(n);
	int totalBit = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		totalBit &= nums[i];
	}
	if (totalBit != 0) {
		cout << 1 << endl;
		return;
	}
	
	vector<int> suffix(n);
	int suffixBit = INT_MAX;
	for (int i = n - 1; i >= 0; i--) {
		suffixBit &= nums[i];
		suffix[i] = suffixBit;
	}
	int current = INT_MAX;
	int total = 0;
	for (int i = 0; i < n - 1; i++) {
		current &= nums[i];
		if (current == 0 && suffix[i + 1] == 0) {
			total++;
			current = INT_MAX;
		}
	}
	cout << total + 1 << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

