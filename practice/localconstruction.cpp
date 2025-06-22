#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> c(n);
	iota(c.begin(), c.end(), 0);

    vector<vector<int>> adj(n);
    for (int op = 1; sz(a) > 1; op++) {
    	vector<int> na, nc;

    	int l = 0, r = sz(a) - 1;
    	while (a[l] == op && a[l + 1] == op) {
    		if (op % 2 == 1) adj[c[l + 1]].push_back(c[l]);
    		else adj[c[l]].push_back(c[l + 1]);
    		l++;
    	}
    	while (a[r] == op && a[r - 1] == op) {
    		if (op % 2 == 1) adj[c[r - 1]].push_back(c[r]);
    		else adj[c[r]].push_back(c[r - 1]);
    		r--;
    	}
    	if (a[l] == op) l++;
    	if (a[r] == op) r--;

    	for (int i = l; i <= r; i++) {
    		if (a[i] == op) {
    			if (i < n - 1 && a[i + 1] == op) {
    				if (op % 2 == 1) adj[c[i + 1]].push_back(c[i]);
    				else adj[c[i]].push_back(c[i + 1]);
    			}
    		}
    		else {
	    		na.push_back(a[i]);
	    		nc.push_back(c[i]);
	    		if (op % 2 == 1) {
	    			if (i < sz(a) - 1) adj[c[i]].push_back(c[i + 1]);
	    			if (i > 0) adj[c[i]].push_back(c[i - 1]);
	    		}
	    		else {
	    			if (i < sz(a) - 1) adj[c[i + 1]].push_back(c[i]);
	    			if (i > 0) adj[c[i - 1]].push_back(c[i]);
	    		}
	    	}
    	}
    	a = na;
    	c = nc;
    }

    // -1 1 1 1 1 -

    // for (int i = 0; i < n; i++) {
    // 	cout << i + 1 << ": ";
    // 	for (int j : adj[i]) cout << j + 1 << " ";
    // 	cout << endl;
    // }

    vector<int> ind(n);
    for (int i = 0; i < n; i++) {
    	for (int j : adj[i]) ind[j]++;
    }
	queue<int> q;
	for (int i = 0; i < n; i++) if (ind[i] == 0) q.push(i);

	vector<int> ord;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ord.push_back(cur);
		for (int i : adj[cur]) {
			ind[i]--;
			if (ind[i] == 0) q.push(i);
		}
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++) ans[ord[i]] = i + 1;
	for (int i : ans) cout << i << " ";
	cout << "\n";

	// -1 < 1 < 1 < 1 > -1
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    