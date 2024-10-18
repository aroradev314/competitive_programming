#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
	freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
	
	ll n, k, m;
	cin >> n >> k >> m;
	
	ll l = 1, r = 1e12 + 5;
	
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		ll given = 0, cur = k;
		
		while ((n - given) / mid > m) {
			given += (n - given) / mid;
			cur--;
		}
		
		if (given + cur * m >= n) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << (l - 1);
}

		
	
	
	
