/*
 * Codeforces Round 855 (Div. 3)
 * Question D
*/ 
#include <set>
#include <iostream>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	string current;
	cin >> current;
	int total = n - 1;
	for (int i = 0; i < n - 2c; i++) {
		if (current.at(i) == current.at(i + 2)) {
			total--;
		}
	}
	cout << total << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
