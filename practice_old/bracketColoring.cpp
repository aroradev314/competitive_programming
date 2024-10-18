// Codeforces Round 149
// D

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void test_case() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int left = 0;
	int balance = 0;
	bool wasNegative;
	vector<int> colors(n);
	for (int i = 0; i < n; i++) {
		wasNegative = (balance < 0);
		balance += (s[i] == '(') ? 1 : -1;
		if (balance == 0) {
			int val = wasNegative + 1;
			for (int j = left; j <= i; j++) {
				colors[j] = val;
			}
			left = i + 1;
		}
	}
	if (balance != 0) {
		cout << -1 << endl;
	}
	else  {
		if (*min_element(colors.begin(), colors.end()) != *max_element(colors.begin(), colors.end())) {
			cout << 2 << endl;
			for (int i : colors) {
				cout << i << " ";
			}
		}
		else {
			cout << 1 << endl;
			for (int i = 0; i < n; i++) {
				cout << 1 << " ";
			}
		}
		
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

