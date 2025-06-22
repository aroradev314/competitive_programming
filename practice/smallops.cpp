#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 1e9;

int min_divs(int a, int k) {
	vector<int> divs;
	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			divs.push_back(i);
			if (a / i != i) divs.push_back(a / i);
		}
	}

	sort(divs.begin(), divs.end());

	vector<int> dp(sz(divs), INF);
	dp[0] = 0;

	for (int i = 1; i < sz(divs); i++) {
		for (int j = 0; j < i; j++) {
			if (divs[i] % divs[j] == 0 && divs[i] / divs[j] <= k) dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	// cout << divs.back() << endl;

	return dp[sz(divs) - 1];
}

void solve() {
	int x, y, k;
	cin >> x >> y >> k;

	int g = gcd(x, y);
	x /= g;
	y /= g;
	// cout << x << " " << y << endl;

	int xd = min_divs(x, k);
	int yd = min_divs(y, k);

	if (xd == INF || yd == INF) cout << "-1\n";
	else cout << xd + yd << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    