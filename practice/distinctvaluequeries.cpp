#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int t[MAX_N];
int a[MAX_N];
int nex[MAX_N];
int n, q;

int sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += t[x];
		x -= x&-x;
	}
	return ans;
}

void add(int x, int val) {
	while (x <= n) {
		t[x] += val;
		x += x&-x;
	}
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<pair<int, int>> queries(q);
	for (int i = 0; i < q; i++) cin >> queries[i].first >> queries[i].second;

	vector<int> ord(q);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) {
		return queries[x] < queries[y];
	});
	
	for (int i = 1; i <= n; i++) nex[i] = -1;
	map<int, int> last;
	for (int i = 1; i <= n; i++) {
		if (last.count(a[i])) {
			nex[last[a[i]]] = i;
		}
		else {
			add(i, 1);
		}
		last[a[i]] = i;
	}

	int bef = 1;
	vector<int> ans(q);
	for (int i : ord) {
		int l = queries[i].first, r = queries[i].second;
		for (int j = bef; j < l; j++) {
			add(j, -1);
			if (nex[j] != -1) add(nex[j], 1);
		}
		ans[i] = sum(r) - sum(l - 1);
		bef = l;
	}

	for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
    