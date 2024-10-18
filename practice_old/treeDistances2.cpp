// Codeforces Round 875
// A
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> perm(n), ans(n);
	for (int i = 0; i < n; i++) {
		cin >> perm[i];
	}
	for (int i = 0; i < n; i++) {
		ans[i] = n - perm[i] + 1;
	}
	for (int i : ans) {
		cout << i << " ";
	}
	
	cout << endl;
}
	
	
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
