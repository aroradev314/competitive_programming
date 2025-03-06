#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
ll dp[MAX_N][3];
int a[MAX_N], c[MAX_N];
int q[MAX_N];
ll ans[MAX_N];

int med(int x, int y, int z) {
	return x ^ y ^ z ^ min({x, y, z}) ^ max({x, y, z});
}

int get(int x, int m) {
	if (x < m) return 0;
	else if (x == m) return 1;
	else return 2; 
}

void solve() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> a[i] >> c[i];

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> q[i];
	vector<int> ord(Q);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(),[&] (int x, int y) {
		return q[x] < q[y];
	});

	for (int i = N; i >= 1; i--) {
		if (2 * i > N) {
			for (int j = 0; j < 3; j++) {
				if (get(a[i], q[ord[0]]) == j) dp[i][j] = 0;
				else dp[i][j] = c[i];
			}
			continue;
		}

		for (int j = 0; j < 3; j++) dp[i][j] = 1e15;
		for (int j = 0; j < 3; j++) {
			ll cost = (get(a[i], q[ord[0]]) == j) ? 0 : c[i];
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					dp[i][med(j, k, l)] = min(dp[i][med(j, k, l)], 
						cost + dp[2 * i][k] + dp[2 * i + 1][l]);
				}
			}
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= N; i++) pq.push({a[i], i});

	ans[ord[0]] = dp[1][1];

	for (int i = 1; i < Q; i++) {
		// as m increases
		if (q[ord[i]] != q[ord[i - 1]]) {
			vector<int> keep;
			while (sz(pq) && pq.top().first <= q[ord[i]]) {
				auto [val, pos] = pq.top();
				pq.pop();
				if (val == q[ord[i]]) keep.push_back(pos);

				for (int w = pos; w >= 1; w /= 2) {
					if (2 * w > N) {
						for (int j = 0; j < 3; j++) {
							if (get(a[w], q[ord[i]]) == j) dp[w][j] = 0;
							else dp[w][j] = c[w];
						}
						continue;
					}

					for (int j = 0; j < 3; j++) dp[w][j] = 1e15;
					for (int j = 0; j < 3; j++) {
						ll cost = (get(a[w], q[ord[i]]) == j) ? 0 : c[w];
						for (int k = 0; k < 3; k++) {
							for (int l = 0; l < 3; l++) {
								dp[w][med(j, k, l)] = min(dp[w][med(j, k, l)], 
									cost + dp[2 * w][k] + dp[2 * w + 1][l]);
							}
						}
					}
				}
			}

			for (int x : keep) pq.push({a[x], x});
		}
		ans[ord[i]] = dp[1][1];
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
    