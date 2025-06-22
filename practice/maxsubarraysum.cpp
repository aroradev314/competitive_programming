#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // a b c 0 0 d e f 0 g h i 
    // first check if there is any subarray that has a sum greater than k, then we lose
    // then check if there are any 2 0s in a row in s, then we win
    // otherwise there are only one zero and we need to see if the left and the right
    // are less than k

    vector<ll> left(n + 2), right(n + 2);
	ll best = 0;
	ll biggest = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0') {
			best = 0;
			continue;
		}
		left[i] = max(best + a[i], a[i]);
		best = left[i];
		biggest = max(biggest, best);
	}
	best = 0;
	for (int i = n; i >= 1; i--) {
		if (s[i - 1] == '0') {
			best = 0;
			continue;
		}
		right[i] = max(best + a[i], a[i]);
		best = right[i];
	}
	if (biggest > k) {
		cout << "No\n";
		return;
	}
	else if (biggest == k) {
		for (int i = 1; i <= n; i++) if (s[i - 1] == '0') a[i] = -1e18;
		cout << "Yes\n";
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1') continue;

		ll cur = max(left[i - 1], 0LL) + max(right[i + 1], 0LL);
		a[i] = k - cur;
		for (int j = i + 1; j <= n; j++) if (s[j - 1] == '0') a[j] = -1e18;
		cout << "Yes\n";
		for (int j = 1; j <= n; j++) cout << a[j] << " ";
		cout << "\n";
		return;
	}

	cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    