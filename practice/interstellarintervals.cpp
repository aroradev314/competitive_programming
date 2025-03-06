#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 5e5 + 10;

int t[MAX_N][2]; // even and odd fenwicks 
int dp[MAX_N];
vector<int> events[MAX_N]; // when to update the dp

int n;

void add(int pos, int x) {
	pos++;
	int mod = pos % 2;

	for (int i = pos; i <= n; i += i&-i) {
		(t[i][mod] += x) %= MOD;
	}
}

int sum(int pos) {
	pos++;
	int mod = pos % 2;
	int s = 0;
	for (int i = pos; i > 0; i -= i&-i) {
		(s += t[i][mod]) %= MOD;
	}
	return s;
}

// sum from [x, y] with same parity as y
int range(int x, int y) {
	int cur = sum(y);

	if ((x % 2) == (y % 2)) x -= 2;
	else x -= 1;

	if (x >= 0) cur -= sum(x);
	while (cur < 0) cur += MOD;

	return cur;
}

void solve() {
	string s;
	cin >> n >> s;

	int nb = n + 1;
	for (int i = n; i >= 0; i--) {
		if (i > 0 && s[i - 1] == 'B') nb = i;
		else if (nb != n + 1) events[nb].push_back(i);
	}

	dp[0] = 1;
	add(0, dp[0]);

	int lr = 0;
	for (int i = 1; i <= n; i++) {
		char c = s[i - 1];
		if (c == 'R') lr = i;
		else {
			if (c == 'X') (dp[i] += dp[i - 1]) %= MOD;

			int y = i - 2;
			int x = lr - (i - lr);

			if (i == 11) cout << x << " " << y << endl;

			if (y >= 0) (dp[i] += range(x, y)) %= MOD;

			add(i, dp[i]);
			for (int pos : events[i]) {
				add(pos, -dp[pos]);
				dp[pos] = 0;
			}
		}
		// cout << dp[i] << " ";
	}
	cout << "\n";

	cout << dp[n] << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) solve();
}