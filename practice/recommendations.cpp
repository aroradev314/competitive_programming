#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> indices(n);
	iota(indices.begin(), indices.end(), 0);
	sort(indices.begin(), indices.end(), [&] (int a, int b) {
		return (l[a] < l[b]);
	});
    multiset<int> c;
    vector<int> ans(n);

    for (int rep = 0; rep < 2; rep++) {
    	sort(indices.begin(), indices.end(), [&] (int a, int b) {
			return (l[a] < l[b]);
		});
		c.clear();

		for (int id = 0; id < n; id++) {
			int i = indices[id];
	    	if (id == 0 || l[i] != l[indices[id - 1]]) {
	    		while (sz(c) && *c.begin() < l[i]) c.erase(c.begin());
	    		c.insert(r[i]);
	    		for (int j = id + 1; j < n && l[indices[j]] == l[i]; j++) c.insert(r[indices[j]]);
	    	}
	    	// if (rep == 0) {
	    	// 	for (int j : c) cout << j << " ";
	    	// 	cout << "\n";
	    	// }

	    	c.erase(c.find(r[i]));
	    	auto x = c.lower_bound(r[i]);
	    	if (x != c.end()) ans[i] += *x - r[i];
	    	c.insert(r[i]);
	    }

	    for (int i = 0; i < n; i++) {
	    	l[i] = INF - l[i];
	    	r[i] = INF - r[i];
	    	swap(l[i], r[i]);
	    } 
    }

    for (int i : ans) cout << i << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    