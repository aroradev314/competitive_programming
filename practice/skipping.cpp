#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 4e5 + 10;
int a[MAX_N], b[MAX_N];
ll pref[MAX_N], dp[MAX_N];
bool visited[MAX_N];

void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) dp[i] = LONG_LONG_MAX;

	pref[0] = 0;
	for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

	dp[1] = 0;
	ll ans = a[1];

	priority_queue<pair<ll, int>> pq;
	pq.push({-dp[1], 1});

	while (!pq.empty()) {
		auto [dist, u] = pq.top();
		dist = -dist;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = true;

		ans = max(ans, pref[u] - dist);
		if (u - 1 != 0 && dist < dp[u - 1]) {
			dp[u - 1] = dist;
			pq.push({-dp[u - 1], u - 1});
		}
		if (dist + a[u] < dp[b[u]]) {
			dp[b[u]] = dist + a[u];
			pq.push({-dp[b[u]], b[u]});
		}
	}

	cout << ans << "\n";

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
