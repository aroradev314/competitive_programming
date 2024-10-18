#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll before(int a) {
	return ((ll) a * a + a) / 2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, x, y;
		cin >> n >> x >> y;
		
		ll lcm = x * y / gcd(x, y);
		ll timesLCM = n / lcm;
		
		ll totalX = n / x - timesLCM;
		ll totalY = n / y - timesLCM;
		
		ll ans = before(n) - before(n - totalX) - before(totalY);
		
		cout << ans << endl;
		
		
	}
}
