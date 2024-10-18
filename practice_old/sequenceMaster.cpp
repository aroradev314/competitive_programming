#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(2 * n + 1);
		long long ans = 0, diff = 0;
		for (int i = 1; i <= 2 * n; i++) {
			cin >> a[i];
			ans += abs(a[i]);
			diff += abs(a[i] - (-1));
		}	
		
		if (n == 1) {
			ans = min(ans, abs(a[2] - a[1]));
		}
		if (n == 2) {
			ans = min(ans, abs(a[1] - 2) + abs(a[2] - 2) + abs(a[3] - 2) + abs(a[4] - 2));
		}
		if (n % 2 == 0) {
			for (int i = 1; i <= 2 *n; i++) {
				ans = min(ans, diff - abs(a[i] - (-1)) + abs(a[i] - n));
			}
		}
		cout << ans << "\n";
	}
}

			
