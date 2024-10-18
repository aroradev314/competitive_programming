// Educational Codeforces Round 146 (Rated for Div. 2)
// A. Coins
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		if (n % 2 == 0 || (n >= k && k % 2 != 0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
