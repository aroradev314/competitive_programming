#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int cnt = n / 2 - 1;
	
	ll e = 0, s = 0;
	for (int i = 0; i < cnt; i++) e += a[i];
	for (int i = 0; i < n; i++) s += a[i];

	ll best_e = e;
	for (int i = 0; i < cnt; i++) {
		e -= a[cnt - 1 - i];
		e += a[n - 1 - i];
		best_e = max(best_e, e);
	} 

	cout << s - best_e << " " << best_e << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}