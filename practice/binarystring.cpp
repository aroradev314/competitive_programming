#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = 1, r = 2;
    vector<char> s(n + 1);

    bool found = false;
    int ans;
    while (r <= n) {
    	if (!found) {
    		cout << "? " << l << " " << r << endl;
    		cin >> ans;
    		int cur = ans;
    		if (ans) {
    			found = true;
    			s[r] = '1';
    			for (int i = r - 1; i >= l; i--) {
    				if (cur) {
    					s[i] = '0';
    					cur--;
    				}
    				else s[i] = '1';
    			}
    		}
    	}
    	else {
    		cout << "? " << l << " " << r << endl;
    		int nans; cin >> nans;
    		// cout << ans << " " << nans << endl;
    		if (nans > ans) s[r] = '1';
    		else s[r] = '0';
    		ans = nans;
    	}
    	r++;
    }
    if (found) {
    	cout << "! ";
    	for (int i = 1; i <= n; i++) cout << s[i];
    	cout << endl;
    }
    else cout << "! IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    