#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> a_mx(n / 2 + 1), b_mx(m / 2 + 1);
    for (int i = 0; i < n / 2; i++) {
    	a_mx[i + 1] = a_mx[i] + a[n - 1 - i] - a[i];
    }
    for (int i = 0; i < m / 2; i++) {
    	b_mx[i + 1] = b_mx[i] + b[m - 1 - i] - b[i];
    }

    vector<ll> ans;
    for (int i = 1; i <= (n / 2) + (m / 2); i++) {
    	int l = max(0, 2 * i - m), r = min(i, n - i);
    	if (l > r) break;
    	while (r - l > 1) {
    		int mid = l + (r - l) / 2;

    		ll left = a_mx[mid - 1] + b_mx[i - (mid - 1)];
    		ll cur = a_mx[mid] + b_mx[i - mid];
    		ll right = a_mx[mid + 1] + b_mx[i - (mid + 1)];

    		if (cur >= left && cur >= right) {
    			l = mid;
    			r = mid;
    			break;
    		}
    		else if (right >= left) {
    			l = mid;
    		}
    		else r = mid;
    	}

    	ll best = 0;
    	for (int j = l; j <= r; j++) best = max(best, a_mx[j] + b_mx[i - j]);

    	ans.push_back(best);
    }

    cout << sz(ans) << "\n";
    if (sz(ans)) {
    	for (ll i : ans) cout << i << " ";
    	cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    