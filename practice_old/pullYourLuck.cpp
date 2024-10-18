// Codeforces Nebius Welcome Round Problem 
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;


void test_case() {
	ll n, x, p;
	cin >> n >> x >> p;
	ll steps = min(2 * n, p);
	for (ll i = 1; i <= steps; i++) {
		ll add = (i * i + i) / 2;
		if ((x + add) % n == 0) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
