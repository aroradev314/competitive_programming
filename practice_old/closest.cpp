#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<bool> right(n);
	right[0] = true;
	for (int i = 1; i < n - 1; i++) {
		right[i] = (a[i + 1] - a[i] < a[i] - a[i - 1]);
		
		
		
	}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
