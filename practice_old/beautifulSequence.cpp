#include <iostream>
#include <vector>
using namespace std;


void test_case() {
	int n;
	cin >> n;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	string answer = "NO";
	for (int i = 1; i <= n; i++) {
		if (nums[i] >= i) {
			answer = "YES";
			break;
		}
	}
	cout << answer << endl;
}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
