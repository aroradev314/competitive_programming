#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int mn = 2e9, mnPos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] < mn) {
			mnPos = i;
			mn = a[i];
		}
	}
	for (int i = mnPos + 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			cout << -1 << "\n";
			return;
		}
	}
	cout << mnPos << "\n";
}
	
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

