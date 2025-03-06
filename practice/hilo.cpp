#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) cin >> a[i];

	set<pair<int, int>> s; // num, index
	vector<int> d(n + 1);

	for (int i = 0; i < n; i++) {
		auto above = s.upper_bound({a[i], 0});
		if (above != s.end()) {
			auto [x, index] = *above;
			if (above == s.begin()) {
				d[a[i]]++;
				d[x]--;
			}
			else {
				above--;
				auto [y, other_index] = *above;
				if (index > other_index) {
					d[a[i]]++;
					d[x]--;
				}
			}
		}
		s.insert({a[i], i});
	}

	for (int i = 0; i <= n; i++) {
		if (i > 0) d[i] += d[i - 1];
		cout << d[i] << "\n";
	}
}
