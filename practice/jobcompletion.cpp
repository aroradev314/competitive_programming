#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	int n;
	cin >> n;

	vector<pair<ll, ll>> jobs(n);
	for (int i = 0; i < n; i++) {
		ll s, t;
		cin >> s >> t;
		ll d = s + t;
		jobs[i] = {d, t};
	}

	sort(jobs.begin(), jobs.end());
	ll time = 0;
	priority_queue<ll> pq;
	int ans = 0;
	for (auto [d, t] : jobs) {
		while (time + t > d && sz(pq) && pq.top() > t) {
			time -= pq.top();
			pq.pop();
		}
		if (time + t <= d) {
			time += t;
			pq.push(t);
		}
		ans = max(ans, sz(pq));
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
    