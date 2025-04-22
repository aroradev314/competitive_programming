#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve(int tt) {
	int n;
	cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll even_sum = 0;
	int mx = 0;
	vector<int> odds;

	for (int i : a) {
		mx = max(mx, i);
		if (i % 2) odds.push_back(i);
		else even_sum += i;
	}

	if (sz(odds) == n || sz(odds) == 0) {
		cout << mx << "\n";
		return;
	}

	sort(odds.begin(), odds.end());
	reverse(odds.begin(), odds.end());

	ll ans = even_sum + odds[0];

	for (int i = 1; i < sz(odds); i++) ans += odds[i] - 1;
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) solve(tt);
}
    