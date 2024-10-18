#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n, z;
	cin >> n >> z;
	vector<int> nums(n + 1);
	vector<long long> pref(n + 1), x(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		pref[i] = pref[i - 1] + nums[i];
		x[i] = x[i - 1] ^ nums[i];
	}
	int l, r;
	cin >> l >> r;
	
	long long ans = (pref[r] - pref[l - 1]) - (x[r] ^ x[l - 1]);
	
	int p = l, q = r;
	for (int i = l; i <= r; i++) {
		int a = i, b = r;
		while (a <= b) {
			int middle = (a + b) / 2;
			if (pref[middle] - pref[i - 1] - (x[middle] ^ x[i - 1]) == ans) {
				if (middle - i < q - p) {
					p = i;
					q = middle;
				}
				b = middle - 1;
			}
			else {
				a = middle + 1;
			}
		}
	}
	cout << p << " " << q << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

				
		
	
	
