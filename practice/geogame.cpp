// Source: https://usaco.guide/general/io

#include <vector>
#include <iostream>
#include <map>
#include <numeric>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	map<int, int> raw;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		raw[num]++;
	}
	
	vector<int> a, c;
	for (auto& [k, v] : raw) {
		a.push_back(k);
		c.push_back(v);
	}

	n = a.size();

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&] (int x, int y) {
		return a[x] < a[y];
	});

	// find the leftmost
	int ans = 0;
	for (int j = 0; j < n; j++) {
		int i = ind[j];
		ans = max(ans, a[i] * min(c[i], m / a[i]));
		if (j < n - 1) {
			int next = ind[j + 1];
			if (a[next] != a[i] + 1) continue;

			if (a[i] * c[i] + a[next] * c[next] <= m) {
				ans = max(ans, a[i] * c[i] + a[next] * c[next]);
				continue;
			}

			int l = 0, r = min(c[i], m / a[i]);
			while (l <= r) {
				int mid = l + (r - l) / 2;
				int left = m - a[i] * mid;
				if (a[next] * c[next] >= left) r = mid - 1;
				else l = mid + 1;
			}


			int leftmost = r + 1, rightmost = min(c[i], m / a[i]);
			int mod = (m - a[i] * leftmost) % a[next];
			if (leftmost > 0) ans = max(ans, (leftmost - 1) * a[i] + c[next] * a[next]);
			if (mod == 0 || mod + (rightmost - leftmost) >= a[next]) ans = m;
			else {
				ans = max(ans, m - mod);
				mod = (m - a[i] * rightmost) % a[next];
				ans = max(ans, m - mod);
			}
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) solve();
}
