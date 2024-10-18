#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	
	ll n, t;
	cin >> n >> t;
	
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		ll x, speed;
		cin >> x >> speed;
		s[i] = x + t * speed;
	}
	ll leastEnd = s[n - 1];
	ll ans = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] < leastEnd) {
			ans++;
			leastEnd = s[i];
		}
	}
	cout << ans << endl;
}
