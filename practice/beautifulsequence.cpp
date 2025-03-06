#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 998244353;
const int MAX_N = 2e5 + 10;
int a[MAX_N];

int add(int x, int y) {
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int ones = 0, seq = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) ones++;
		else if (a[i] == 2) {
			seq = add(seq, seq + ones);
		}
		else {
			ans = add(ans, seq);
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
    