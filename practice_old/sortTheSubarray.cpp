#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int left = -1, right = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (left == -1) {
				left = i;
			}
			right = i;
		}
	}
	while (left > 0 && b[left] >= b[left - 1]) {
		left--;
	}
	while (right < n - 1 && b[right] <= b[right + 1]) {
		right++;
	}
	cout << left + 1 << " " << right + 1 << endl;
}
		
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
	
