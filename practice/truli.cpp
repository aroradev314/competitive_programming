#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m, -1));

    if (m % k != 0) {
    	int cur = 1;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			cout << cur << " ";
    			cur++;
    			if (cur > k) cur = 1;
    		}
    		cout << "\n";
    	}
    }
    else {
    	for (int i = 0; i < n; i++) {
    		int cur = 1;
    		if (i % 2 == 1) cur++;
    		for (int j = 0; j < m; j++) {
    			cout << cur << " ";
    			cur++;
    			if (cur > k) cur = 1;
    		}
    		cout << "\n";
    	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    