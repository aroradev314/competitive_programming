#include <bits/stdc++.h>
#define int long long
using namespace std;

const int32_t MAX_N = 2e5 + 10;
int a[MAX_N];
int tree[MAX_N];
int l[MAX_N], r[MAX_N];
vector<int> adj[MAX_N];
int n, q;

int sum(int k) {
	int s = 0;
	while (k > 0) {
		s += tree[k];
		k -= (k&-k);
	}
	return s;
}

void add(int i, int x) {
	while (i <= n) {
		tree[i] += x;
		i += (i&-i);
	}
}

void dfs(int u, int p, int& k) {
	l[u] = k;
	for (int v : adj[u]) {
		if (v == p) continue;
		k++;
		dfs(v, u, k);
	}	
	r[u] = k;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int k = 1;
	dfs(1, -1, k);
	for (int i = 1; i <= n; i++) {
		add(l[i], a[i]);
		add(r[i] + 1, -a[i]);
	}

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int s, x;
			cin >> s >> x;
			int change = x - a[s];
			a[s] = x;
			// for (int i = 1; i <= n; i++) cout << sum(l[i]) - sum(l[i] - 1) << " ";
			add(l[s], change);
			add(r[s] + 1, -change);
			// for (int i = 1; i <= n; i++) cout << sum(l[i]) - sum(l[i] - 1) << " ";
		}
		else {
			int s;
			cin >> s;
			cout << sum(l[s]) << "\n";
		}
	}


}