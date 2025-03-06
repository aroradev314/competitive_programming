#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 2e9;
const int MAX_N = 2e5 + 10;
int t[MAX_N];
vector<int> each[MAX_N];
int l[MAX_N], r[MAX_N];
int diff[MAX_N];
int n, q;

ll sum(int k) {
	ll s = 0;
	while (k >= 1) {
		s += t[k];
		k -= k&-k;
	}
	return s;
}

void add(int k, int x) {
	while (k <= n) {
		t[k] += x;
		k += (k&-k);
	}
}


void solve() {
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	stack<pair<int, int>> s;
	s.push({2e9, -1});

	for (int i = 1; i <= n; i++) {
		while (s.top().first < a[i]) s.pop();
		if (s.top().second != -1) {
			diff[i] = s.top().first - a[i];
			each[s.top().second].push_back(i);
		}
		s.push({a[i], i});
	}
	for (int i = 1; i <= n; i++) cout << diff[i] << " ";
	cout << endl;

	for (int i = 1; i <= n; i++) add(i, diff[i]);

	for (int i = 0; i < q; i++) cin >> l[i] >> r[i];

	vector<int> inds(q);
	iota(inds.begin(), inds.end(), 0);
	sort(inds.begin(), inds.end(), [&](int x, int y) {
		return (l[x] < l[y]);
	});

	// for every element, if it has something greater than it behind itz

	int last = -1;
	vector<ll> ans(q);
	for (int i : inds) {
		int left = l[i], right = r[i];
		if (last != -1 && left != last) {
			for (int j : each[last]) {
				add(j, -diff[j]);
			}
		}

		ans[i] = sum(right) - sum(left - 1);
		last = left;
	}

	for (ll i : ans) cout << i << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int tc = 1;
    while (tc--) solve();
}
    