#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int a[MAX_N];
int n;

int find(ll pos) {
	if (pos <= n) return a[pos];
	int ans = 0;
	for (int i = 1; i <= min((ll) n, pos / 2); i++) ans += a[i];
	ans %= 2;
	
	ll last = pos / 2;
	if (last % 2 == 0 && last > n) {
		ans += find(last);
	}

	return ans % 2;
}

void solve() {
    ll l, r;
    cin >> n >> l >> r; 

    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n % 2 == 0) {
    	int cur = 0;
    	for (int i = 1; i <= (n + 1) / 2; i++) cur += a[i];
    	a[n + 1] = cur % 2;
    	n++;
    }

    int ans = find(l);
	
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    