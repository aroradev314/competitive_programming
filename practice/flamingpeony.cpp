#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 5050;

int ck_min(int a, int b) {
	if (a == -1) return b;
	else if (b == -1) return a;
	else return min(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int g = a[0];
    for (int i = 1; i < n; i++) g = gcd(g, a[i]);

    for (int i = 0; i < n; i++) a[i] /= g;
    sort(a.begin(), a.end());
	if (a[0] == 1) {
		int ans = 0;
		for (int i : a) if (i != 1) ans++;
		cout << ans << "\n";
		return;
	}

    vector<int> dp(MAX_N, -1);
	for (int i = 0; i < n; i++) {
		vector<int> ndp = dp;
		ndp[a[i]] = 1;
		// we can make a new gcd
		for (int j = 1; j < MAX_N; j++) if (dp[j] != -1) ndp[gcd(j, a[i])] = ck_min(ndp[gcd(j, a[i])], dp[j] + 1);
		dp = ndp;
	}
	
	int ans = dp[1] - 1;
	bool found = false;
	for (int i : a) {
		if (i != 1) {
			if (found) ans++;
			else found = true;
		}
	}

	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    