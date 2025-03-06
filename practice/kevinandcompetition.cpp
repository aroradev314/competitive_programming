#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n), p(m);
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < m; i++) cin >> p[i];

    int k = r[0];
    sort(r.begin(), r.end());
	vector<int> num(m); // how many people above kevin can solve the problem

	for (int i = 0; i < m; i++) {
		if (p[i] <= k) continue;
		auto it = upper_bound(r.begin(), r.end(), p[i] - 1);
		int above = n - (it - r.begin());
		num[i] = above;
	}

	sort(num.begin(), num.end());

	for (int i = 1; i <= m; i++) {
		ll ans = 0;
		for (int j = i - 1; j < m; j += i) {
			ans += num[j] + 1;
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    