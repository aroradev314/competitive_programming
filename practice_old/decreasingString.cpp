#include <iostream>
#include <stack>
#include <vector>
#define ll long long
using namespace std;

void test_case() {
	string s;
	cin >> s;
	int n = s.length();
	
	ll p; 
	cin >> p;
	
	ll total = 0;
	int finalLength = n;
	while (total + finalLength < p) {
		total += finalLength;
		finalLength--;
	}
	
	
	vector<bool> stillThere(n, true);
	stack<pair<int, int>> letters;
	letters.push({s[0], 0});
	
	int ind = 1, currentLength = n;
	while (currentLength > finalLength) {
		if (ind == n || (letters.size() > 0 && s[ind] < letters.top().first)) {
			stillThere[letters.top().second] = false;
			letters.pop();
			currentLength--;
		}
		else {
			letters.push({s[ind], ind});
			ind++;
		}
	}
	int current = 0;
	p -= total;
	for (int i = 0; i < n; i++) {
		if (stillThere[i]) {
			current++;
		}
		if (current == p) {
			cout << s[i];
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

