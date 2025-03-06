#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

ll ans;
int n, k;

void solve() {
    cin >> n >> k;
    ans = 0;

    int x = n / 2;
    if (n % 2) {
    	ans += n / 2 + 1;
    }

    ll num = 1;
    while (x >= k) {
    	if (x % 2) {
    		ans += (n + 1) * num;
    	}
    	x /= 2;
    	num *= 2;
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
    