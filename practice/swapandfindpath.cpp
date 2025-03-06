#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
    	int cur = 0;
    	for (int j = 0; j < n; j++) {
    		if (j == i) cur += a[j] + b[j];
    		else cur += max(a[j], b[j]);
    	}
    	ans = max(ans, cur);
    }

    cout << ans << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    