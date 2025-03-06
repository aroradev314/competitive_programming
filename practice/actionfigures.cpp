#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		ans += i + 1;
    		pq.push(0);
    	}
		else if (sz(pq)) {
			ans += pq.top();
			pq.pop();
			pq.push(i + 1);
		}
		else {
			ans += i + 1;
			pq.push(0);
		}
    	// cout << ans << "\n";
    }
    cout << ans << "\n";

    // ans = 1, pq = {1}
    // ans = 2, pq = {0, 1}
    // 11111
    // ans = 1, pq = {0}
    // ans = 1, pq = {2}
    // ans = 3, pq = {3}
    // because we used the 2 for the three, the 0 should return
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    