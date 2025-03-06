#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int a[MAX_N], b[MAX_N];
bool a_plus[MAX_N], a_neg[MAX_N], b_plus[MAX_N], b_neg[MAX_N], ans_plus[MAX_N], ans_neg[MAX_N];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    ll asum = 0, bsum = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	asum += a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    	bsum += b[i];
    }

    for (int i = 0; i < n; i++) {
    	if (abs(asum - a[i]) > MAX_N) continue;
    	if (asum - a[i] < 0) a_neg[abs(asum - a[i])] = true;
    	else a_plus[asum - a[i]] = true;
    }

    for (int i = 0; i < m; i++) {
    	if (abs(bsum - b[i]) > MAX_N) continue;
    	if (bsum - b[i] < 0) b_neg[abs(bsum - b[i])] = true;
    	else b_plus[bsum - b[i]] = true;
    }


    for (ll i = 1; i <= MAX_N; i++) {
    	for (ll j = 1; j <= MAX_N; j++) {
    		if (i * j > MAX_N) break;
    		if (a_neg[i] && b_plus[j]) ans_neg[i * j] = true;
    		if (a_plus[i] && b_neg[j]) ans_neg[i * j] = true;
    		if (a_plus[i] && b_plus[j]) ans_plus[i * j] = true;
    		if (a_neg[i] && b_neg[j]) ans_plus[i * j] = true;
    	}
    }

    while (q--) {
    	int x;
    	cin >> x;
    	bool ans = (x < 0 ? ans_neg[-x] : ans_plus[x]);
    	cout << (ans ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    