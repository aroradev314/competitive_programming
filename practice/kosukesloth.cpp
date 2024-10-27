#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	ll n;
	int k;
	cin >> n >> k;
	n %= MOD;

	ll first = 1 % k, second = 1 % k;
	for (int i = 1; i <= 6 * k; i++) {
		if (first == 0) {
			cout << (n * i) % MOD << "\n";
			return;
		}
		int temp = second;
		(second += first) %= k;
		first = temp;
	}
	assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    