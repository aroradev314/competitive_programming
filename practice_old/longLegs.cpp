// Educational Codeforces Round 146 (Rated for Div. 2)
// B. Long Legs
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int MAX_K = 100000;

void test_case() {
	int a, b;
	cin >> a >> b;
	int mn = INT_MAX;
	
	for (int i = 1; i <= MAX_K; i++) {
		int total = 0;
		total += i - 1;
		total += a / i;
		total += b / i;
		if (a % i != 0) { total++; }
		if (b % i != 0) { total++; }
		mn = min(total, mn);
	}
	cout << mn << endl;
}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
