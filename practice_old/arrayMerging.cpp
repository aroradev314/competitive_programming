// Codeforces Round 875
// B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int MAX_N = 200001;


void test_case() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), longestA(2 * n + 1), longestB(2 * n + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	int currentA = 1, currentB = 1;
	
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			currentA++;
		}
		else {
			longestA[a[i - 1]] = max(longestA[a[i - 1]], currentA);
			currentA = 1;
		}
		
		if (b[i] == b[i - 1]) {
			currentB++;
		}
		else {
			longestB[b[i - 1]] = max(longestB[b[i - 1]], currentB);
			currentB = 1;
		}
	}
	longestA[a[n - 1]] = max(longestA[a[n - 1]], currentA);
	longestB[b[n - 1]] = max(longestB[b[n - 1]], currentB);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, longestA[a[i]] + longestB[a[i]]);
		ans = max(ans, longestA[b[i]] + longestB[b[i]]);
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

