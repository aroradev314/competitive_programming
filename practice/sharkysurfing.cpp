#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> hurdles(n);
    vector<pair<int, int>> values(m);

    for (int i = 0; i < n; i++) cin >> hurdles[i].first >> hurdles[i].second;
    for (int i = 0; i < m; i++) cin >> values[i].first >> values[i].second;

    ll power = 1;
	priority_queue<int> pq;
	int ans = 0, cur = 0;

	for (auto [l, r] : hurdles) {
		while (cur < m && values[cur].first < l) {
			pq.push(values[cur].second);
			cur++;
		}
		int len = r - l + 1;
		while (sz(pq) && power <= len) {
			power += pq.top();
			ans++;
			pq.pop();
		}
		if (power <= len) {
			cout << "-1\n";
			return;
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
    