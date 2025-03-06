#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 2e9;
const int MAX_N = 2e5 + 10;
const int K = 25;
int a[MAX_N], diff[MAX_N];
int st[K + 1][MAX_N];

int f(int x, int y) {
	if (x == 0) return y;
	else if (y == 0) return x;
	return gcd(x, y);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) st[0][i] = abs(a[i] - a[i - 1]);

    for (int i = 1; i <= K; i++) {
    	for (int j = 2; j + (1 << i) - 1 <= n; j++) {
    		st[i][j] = f(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]);
    		// cout << i << " " << j << " " << st[i][j] << endl;
    	}
    }


    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	if (l == r) cout << "0 ";
	    else {
	    	l++;
	    	int ans = 0;
	    	for (int i = K; i >= 0; i--) {
	    		if ((1 << i) <= r - l + 1) {
	    			// cout << i << " " << l << " " << st[i][l] << endl;
	    			ans = f(ans, st[i][l]);
	    			l += (1 << i);
	    		}
	    	}
		    cout << ans << " ";
	    }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    