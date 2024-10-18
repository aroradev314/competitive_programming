#include <iostream>
#include <vector>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	long long ans = a[n - 1];
	long long s = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (s < 0) {
			ans += a[i];
		}
		else {
			ans += a[i] + s;
		}
		s += a[i];
	}
	cout << ans << "\n";
}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

