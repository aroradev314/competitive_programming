#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		
		long long cur = 0, ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] == a[i]) {
				ans += cur;
				cur += i;
			}
			else {
				cur = i;
			}
		}
		
		cout << ans << "\n";
	}
}

			
			
			
