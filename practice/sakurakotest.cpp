#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
int a[MAX_N];
int pref[MAX_N];
int ans[MAX_N];

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pref[a[i]]++; 

    for (int i = 1; i <= n; i++) pref[i] += pref[i - 1];

    for (int i = 1; i <= n; i++) {
    	int l = 0, r = i - 1;
    	while (l <= r) {
    		int mid = l + (r - l) / 2;

    		int valid = 0;
    		for (int j = 0; j * i <= n; j++) {
    			valid += pref[min(n, j * i + mid)] - pref[j * i - 1];
    		}

    		if (valid > n / 2) r = mid - 1;
    		else l = mid + 1;
    	}
    	ans[i] = r + 1;
    }

    while (q--) {
    	int x;
    	cin >> x;
    	cout << ans[x] << " ";
    }
    cout << "\n";

    for (int i = 1; i <= n; i++) {
    	pref[i] = 0;
    	a[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    