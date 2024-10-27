#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX_N = 1e6 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(), x.end());
	cin >> q;

	vector<ll> left_dist(MAX_N), right_dist(MAX_N);
	ll left = 0, right = 0;
	for (int i : x) right += i + 1;
	int pnt = 0;
	for (int i = 0; i <= x[n - 1]; i++) {
		right -= (n - pnt);
		left += pnt;
		while (pnt < n && x[pnt] == i) pnt++;
		left_dist[i] = left;
		right_dist[i] = right;
	}

	int a, b;
	for (int query = 0; query < q; query++) {
		cin >> a >> b;
		int l = x[0], r = x[n - 1];
		// for (int i = 0; i <= x[n - 1]; i++) cout << a * left_dist[i] + b * right_dist[i] << " ";
		// cout << endl;

		while (r - l > 2) {
			int first = l + (r - l) / 3;
			int second = r - (r - l) / 3;

			ll first_cost = a * left_dist[first] + b * right_dist[first];
			ll second_cost = a * left_dist[second] + b * right_dist[second];

			if (first_cost > second_cost) l = first;
			else r = second;
		}
		ll ans = LONG_LONG_MAX;
		for (int i = l; i <= r; i++) ans = min(ans, a * left_dist[i] + b * right_dist[i]);
		cout << ans << "\n";
	}
}