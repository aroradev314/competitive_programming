#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

ll MOD = 1e9 + 7;

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), k(n);
	ll div = 1;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> k[i];
		div = mul(div, k[i] + 1);
	}
	
	
	

