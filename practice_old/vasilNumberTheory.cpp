#include <vector>
#include <iostream>
#include <map>
#define ll long long
using namespace std;

map<int, int> id;
const int MAX_N = 1e6 + 5;

ll factorize(__int128 num, map<ll, int>& factors) {
	factors.clear();
	for (ll i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			factors[i]++;
			num /= i;
		}
	}
	if (num > 1) factors[num]++;
	ll ans = 1;
	for (auto& [prime, power] : factors) {
		ans *= (power + 1);
	}
	return ans;
}

void test_case() {
	ll n;
	int q;
	cin >> n >> q;
	
	map<ll, int> original;
	ll d = factorize(n, original);
	map<ll, int> cur;
	
	__int128 curNum = n;
	for (int i = 0; i < q; i++) {
		int type; cin >> type;
		if (type == 1) {
			ll x; cin >> x;
			curNum *= x;
			d = factorize(curNum, cur);
			// cout << curNum << " " << d << endl;
			if (curNum % d == 0) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			curNum = n;
			cur = original;
		}
	}
	cout << endl;
}

int main() {
	vector<bool> prime(MAX_N + 5, true);
	for (int i = 2; i <= MAX_N; i++) {
		if (!prime[i]) continue;
		
		for (int j = i + i; j <= MAX_N; j += i) {
			prime[j] = false;
		}
	}
	int cur = 0;
	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i]) {
			id[i] = cur++;
		}
	}

	
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

