#include <algorithm>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;

void test_case() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	ll total = 0;
	for (int i = 0; i < n; i++) { 
		cin >> a[i]; 
		total += a[i];
	}
	sort(a.rbegin(), a.rend());
		
	for (int i = 0; i < k; i++) {
		total -= a[i];
	}
	
	int beginInd = k - 1;
	int endInd = n - 1;
	ll ans = 0;
	while (beginInd >= 0 && endInd >= 1) {
		ans = max(ans, total);
		total += a[beginInd];
		total -= a[endInd];
		total -= a[endInd - 1];
		beginInd	--;
		endInd -= 2;
	}
	ans = max(ans, total);
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

