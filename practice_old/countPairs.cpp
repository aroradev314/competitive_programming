/*
 * Codeforces Round 855 (Div. 3)
 * Question B
*/ 

#include <vector>
#include <iostream>
#include <cctype>
using namespace std;

void test_case() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> amount(26);
	int total = 0;
	for (int i = 0; i < n; i++) {
		char current = s.at(i);
		int pos = tolower(current)-'a';
		if (current == tolower(current)) {
			if (amount[pos] > 0) {
				total++;
			}
			amount[pos]--;
		}
		else {
			if (amount[pos] < 0) {
				total++;
			}
			amount[pos]++;
		}
	}
	int remaining = 0;
	for (int i : amount) {
		remaining += abs(i) / 2;
	}
	total += min(k, remaining);
	cout << total << endl;
}
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
