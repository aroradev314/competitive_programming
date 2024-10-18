#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) { cin >> p[i]; }
		
		vector<bool> dp(n);
		int mn = 1e9, mnWin = 1e9;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (mn < p[i] && mnWin > p[i]) {
				ans++;
				dp[i] = true;
				mnWin = min(mnWin, p[i]);
			}
			mn = min(mn, p[i]);
		}
		cout << ans << endl;
	}
}

				
	
