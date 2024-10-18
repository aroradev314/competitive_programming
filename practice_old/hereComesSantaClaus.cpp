#include <vector>
#include <iostream>
using namespace std;

long double avg(int a, int b) {
	double ans = (a + b) / 2;
	if ((a + b) % 2 == 1) {
		ans += 0.5;
	}
	return ans;
}

void test_case() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	long double ans;
	if (n == 5) {
		ans = avg(nums[n - 1], nums[n - 3]) - avg(nums[0], nums[1]);
		ans = max(ans, avg(nums[n - 1], nums[n - 2]) - avg(nums[0], nums[2]));
	}
	else {
		ans = avg(nums[n - 1], nums[n - 2]) - avg(nums[0], nums[1]);
	}
	cout << std::fixed << ans << endl;
}

int main() {
	freopen("here_comes_santa_claus_input.txt", "r", stdin);
	freopen("santa_claus_full_out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		test_case();
		
	}
}
