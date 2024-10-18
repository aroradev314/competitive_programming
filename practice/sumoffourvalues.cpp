// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	

	map<int, pair<int, int>> which;
	int p = -1, b = -1, c = -1, d = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int missing = x - a[i] - a[j];
			if (which.count(missing)) {
				p = which[missing].first;
				b = which[missing].second;
				c = i + 1;
				d = j + 1;
			}
		}
		for (int j = 0; j < i; j++) which[a[i] + a[j]] = {j + 1, i + 1};
	}
	if (p == -1) cout << "IMPOSSIBLE";
	else cout << p << " " << b << " " << c << " " << d << "\n";
}
