#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n, k;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	cin >> k;
	
	vector<int> val(n), pos(n);
	val[n - 1] = nums[n - 1];
	pos[n - 1] = n - 1;
	
	for (int i = n - 2; i >= 0; i--) {
		val[i] = val[i + 1];
		pos[i] = pos[i + 1];
		if (nums[i] < val[i]) {
			val[i] = nums[i];
			pos[i] = i;
		}
	}
	
	vector<int> times(n);
	times[pos[0]] += k / val[0];
	int rem = (k >= val[0] ? k % val[0] : 0);
	int last = pos[0];
	
	for (int i = 0; i < n; i++) {
		if (pos[i] == pos[0] || i != pos[i]) continue;
		int difference = val[i] - val[last];
		int t = min(rem / difference, times[last]);
		times[last] -= t;
		times[i] += t;
		rem -= t;
		last = i;
	}
	
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = -1 * times[i];
	}
	pref[0] = k / val[0];
	int current = 0;
	for (int i = 0; i < n; i++) {
		current += pref[i];
		cout << current << " ";
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

