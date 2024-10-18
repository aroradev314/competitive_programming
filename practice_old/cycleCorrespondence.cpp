#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	set<int> rem;
	for (int i = 1; i <= n; i++) {
		rem.insert(i);
	}
	
	vector<int> a(k), b(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		rem.erase(a[i]);
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		rem.erase(b[i]);
	}
	
	int ans = 0;
	for (int rep = 0; rep < 2; rep++) {
		map<int, int> seen;
		for (int i = 0; i < k; i++) {
			seen[a[i]] = i;
		}
		map<int, int> cnt;
		for (int i = 0; i < k; i++) {
			if (seen.count(b[i])) {
				if (seen[b[i]] >= i) {
					cnt[seen[b[i]] - i]++;
				}
				else {
					cnt[seen[b[i]] + (k - i)]++;
				}
			}
		}
		
		int cur = 0;
		for (auto& [key, diff] : cnt) {
			// cout << key << " " << diff << endl;
			cur = max(cur, diff);
		}
	
		ans = max(ans, cur);
		reverse(b.begin(), b.end());
	}
	
	cout << ans + rem.size() << endl;
}

			
	
	
		
