#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void test_case() {
	// ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	
    int n;
	cin >> n;
	vector<int> a(n), d(n), l(n), r(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> d[i];
	
	for (int i = 0; i < n; i++) {
		if (i > 0) l[i] = i - 1;
		if (i < n - 1) r[i] = i + 1;
	}
	l[0] = -1;
	r[n - 1] = -1;
	
	vector<int> damage(n);
	for (int i = 0; i < n; i++) {
		if (l[i] != -1) {
			damage[l[i]] += a[i];
		}
		if (r[i] != -1) {
			damage[r[i]] += a[i];
		}
	}
	
	set<int> alive;
	for (int i = 0; i < n; i++) alive.insert(i);
	set<int> dead;
	for (int i = 0; i < n; i++) {
		if (damage[i] > d[i]) {
			dead.insert(i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << dead.size() << " ";
		
		set<int> candidates;
		
		for (int j : dead) {
			alive.erase(j);
			if (r[j] != -1 && !dead.count(r[j])) {
				candidates.insert(r[j]);
			}
			if (l[j] != -1 && !dead.count(l[j])) {
				candidates.insert(l[j]);
			}
		}
		
		for (int j : candidates) {
			
			if (upper_bound(alive.begin(), alive.end(), j) == alive.end()) {
				r[j] = -1;
			}
			else {
				r[j] = *upper_bound(alive.begin(), alive.end(), j);
				l[r[j]] = j;
			}
			
			if (lower_bound(alive.begin(), alive.end(), j) == alive.begin()) {
				l[j] = -1;
			}
			else {
				l[j] = *(--lower_bound(alive.begin(), alive.end(), j));
				r[l[j]] = j;
			}
			
			if (r[j] != -1) candidates.insert(r[j]);
			if (l[j] != -1) candidates.insert(l[j]);
		}
		
		dead.clear();
		for (int j : candidates) {
			damage[j] = (r[j] != -1 ? a[r[j]] : 0) + (l[j] != -1 ? a[l[j]] : 0);
			if (damage[j] > d[j]) dead.insert(j);
		}
	}
	
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

