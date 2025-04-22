#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> b[i];

    ll mx = 0;
	for (int i : b) mx = max(mx, (ll) i);

	vector<int> s;
	for (int i : b) if (i != mx) s.push_back(i);
	sort(s.begin(), s.end());

	vector<int> ans;
	ll d = 0;
	ll val;
	for (int i = 0; i < sz(s); i++) {
		if (i % 2 == 0) {
			val = s[sz(s) - 1 - i / 2];
			d -= val;
		}
		else {
			val = s[i / 2];
			d += val;
		}
		ans.push_back(val);
		// cout << val << endl;
	}


	cout << mx << " ";
	cout << mx - d << " ";
	for (int i : ans) cout << i << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    