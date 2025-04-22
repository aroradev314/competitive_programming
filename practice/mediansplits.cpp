#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<bool> pref(n), suff(n); 
	int good = 0, bad = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= k) good++;
		else bad++;
		if (good >= bad) pref[i] = true;
		if (i > 0) pref[i] = pref[i] || pref[i - 1];
	}
	good = 0, bad = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= k) good++;
		else bad++;
		if (good >= bad) suff[i] = true;
		if (i < n - 1) suff[i] = suff[i] || suff[i + 1];
	}

	bool works = false;
	for (int i = 0; i < n - 1; i++) {
		if (pref[i] && suff[i + 2]) {
			works = true;
			break;
		}
	}

	for (int rep = 0; rep < 2; rep++) {
		good = 0, bad = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= k) good++;
			else bad++;
			pref[i] = (good >= bad);
		}

		good = 0, bad = 0;
		int mn = 1e9;
		for (int i = n - 1; i > 0; i--) {
			if (a[i] <= k) good++;
			else bad++;
			if (good - bad >= mn && pref[i - 1]) {
				works = true;
				break;
			}
			mn = min(mn, good - bad);
		}

		reverse(a.begin(), a.end());
	}

	cout << (works ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    