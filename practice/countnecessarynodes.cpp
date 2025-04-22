#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void dfs(int l, int r, int tl, int tr, vector<int>& v) {
	if (l >= tr || r <= tl) return;
	// cout << l << " " << r << " " << tl << " " << tr << endl;
	if (l <= tl && tr <= r) {
		v.push_back(tr - tl);
		return;
	}

	dfs(l, r, tl, (tl + tr) / 2, v);
	dfs(l, r, (tl + tr) / 2, tr, v);
}

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    vector<int> a, b;
    dfs(l1, r1, 0, 1<<25, a);
    dfs(l2, r2, 0, 1<<25, b);

    // for (auto d1 : a) cout << d1 << " ";
    // cout << endl;
    // for (auto d2 : b) cout << d2 << " ";
    // cout << endl;

    ll ans = 0;
    for (auto d1 : a) {
    	for (auto d2 : b) {
    		ans += max(d2 / d1, d1 / d2);
    	}
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
    