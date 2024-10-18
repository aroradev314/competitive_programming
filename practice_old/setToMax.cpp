#include <iostream>
#include <vector>
#include <array>
#include <stack>
// #include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	vector<array<int, 3>> ops;
	stack<pair<int, int>> as{{{2e9, -1}}}, bs {{{-1, -1}}}; 
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		while (a[i] >= as.top().first) as.pop();
		while (a[i] <= bs.top().first) bs.pop();
		
		l[i] = max(as.top().second, bs.top().second) + 1;
		
		as.push({a[i], i});
		bs.push({b[i], i});
	}
	
	while (as.size()) as.pop();
	while (bs.size()) bs.pop();
	as.push({2e9, n});
	bs.push({-1, n}); 
	
	for (int i = n - 1; i >= 0; i--) {
		while (a[i] >= as.top().first) as.pop();
		while (a[i] <= bs.top().first) bs.pop();
		
		if (a[i] == 3) cout << as.top().second << " " << bs.top().second << endl;
		r[i] = min(as.top().second, bs.top().second) - 1;
		ops.push_back({a[i], l[i], r[i]});
		
		as.push({a[i], i});
		bs.push({b[i], i});
	}
	
	reverse(ops.begin(), ops.end());
	for (auto& [num, x, y] : ops) {
		cout << num << " " << x << " " << y << endl;
	}
	
	sort(ops.begin(), ops.end());
	for (auto& [num, x, y] : ops) {
		for (int i = x; i <= y; i++) a[i] = num;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

