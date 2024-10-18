// Codeforces Round 855 (Div. 3)
// Problem E1
#include <vector>
#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

void test_case() {
	ll n;
	cin >> n;
	ll left = -1, right = 1e9;
	while (right - left > 1) {
		ll middle = left + (right - left) / 2;
		if (middle * middle >= n) {
			right = middle;
		}
		else {
			left = middle;
		}
	}
	cout << right - 1 << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
