#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define int long long
typedef long double ld;
using namespace std;

const int INF = 2e9;

int ceil_div(int a, int b) {
	return (a + b - 1) / b;
}

void solve(int tc) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n), x(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> x[i];

    int l = 1, r = INF;
	vector<pair<int, int>> ints;
	while (l <= r) {
		int q = l + (r - l) / 2;
		ints.clear();
		for (int i = 0; i < n; i++) {
			int diff = m - ceil_div(h[i], q);
			if (diff < 0) continue;
			ints.push_back({x[i] - diff, x[i] + diff});
		}
		sort(ints.begin(), ints.end());
		bool works = false;

		priority_queue<int, vector<int>, greater<int>> d;
		int cur = 0;
		for (int i = 0; i < sz(ints); i++) {
			cur++;
			d.push(ints[i].second);
			while (sz(d) && d.top() < ints[i].first) {
				cur--;
				d.pop();
			}
			if (cur >= k) {
				works = true;
				break;
			}
		}

		if (works) r = q - 1;
		else l = q + 1;
	}

	cout << (r == INF ? -1 : r + 1) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
    