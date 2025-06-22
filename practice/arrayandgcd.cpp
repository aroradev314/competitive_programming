#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e7 + 10;
ll MX_SUM = MAX_N * 1e9;
int a[MAX_N];
bool prime[MAX_N];
ll pref[MAX_N];
ll ax[MAX_N];

void solve() {
    // remove the first i elements and then see if the other elements are greater 
    // then the first n - i prime numbers 
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) ax[i] = ax[i - 1] + a[i];

	ll tot = ax[n];
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (tot - ax[mid] >= pref[n - mid]) {
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	cout << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < MAX_N; i++) prime[i] = true;

    for (int i = 2; i < MAX_N; i++) {
    	if (!prime[i]) continue;
    	for (int j = i + i; j < MAX_N; j += i) prime[j] = false;
    }

	int cur = 1;
	for (int i = 2; i < MAX_N; i++) {
		if (prime[i]) {
			pref[cur] = pref[cur - 1] + i;
			if (pref[cur] > MX_SUM) {
				break;
			}
			cur++;
		}
	}

    int t;
    cin >> t;
    while (t--) solve();
}
    