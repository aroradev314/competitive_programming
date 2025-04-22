#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    ll ans = 0;
    multiset<int> s;
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (c >= k) {
    		ans += d[i];
    		s.insert(d[i]);
    		c -= k;
    	}
    	else if (sz(s) && d[i] > *s.begin()) {
    		ans -= *s.begin();
    		ans += d[i];
    		c++;
    		s.erase(s.begin());
    		s.insert(d[i]);
    	}
    	else c++;
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
    