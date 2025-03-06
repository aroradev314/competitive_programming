#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 200200;
const int MOD = 1e9 + 7;
int power[MAX_N];

int add(int a, int b) {
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	a = (int) ((a * 1LL * b) % MOD);
	return a;
}

void solve() {
	power[0] = 1;
	for (int i = 1; i < MAX_N; i++) power[i] = mul(power[i - 1], 2);

	int n;
	cin >> n;
	vector<pair<int, int>> s(n);
	for (int i = 0; i < n; i++) cin >> s[i].first >> s[i].second;
	sort(s.begin(), s.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (sz(pq) && pq.top() < s[i].first) pq.pop();
		ans = add(ans, ans);
		ans = add(ans, power[i - sz(pq)]);
		pq.push(s[i].second);
	}

	cout << ans << "\n";
}

int main() {
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    