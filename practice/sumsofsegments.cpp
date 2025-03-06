#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll cur = 0, pref = 0;
	for (int i = 1; i <= n; i++) {
		pref += a[i];
		cur += pref;
	}

	vector<ll> blocks(n + 1), blocks_pref(n + 1);
	blocks[1] = cur;
	blocks_pref[1] = cur;
	vector<ll> len(n + 1), len_pref(n + 1);
	len[1] = n;
	len_pref[1] = n;
	for (ll i = 2; i <= n; i++) {
		cur -= (n - i + 2) * a[i - 1];
		blocks[i] = cur;
		blocks_pref[i] = blocks[i] + blocks_pref[i - 1];
		len[i] = len[i - 1] - 1;
		len_pref[i] = len[i] + len_pref[i - 1];
	}

	vector<ll> seq_pref(n + 1);
	for (int i = 1; i <= n; i++) {
		seq_pref[i] = seq_pref[i - 1] + (a[i] * (n - i + 1));
	}

	int q;
	cin >> q;
	while (q--) {
		ll l, r;
		cin >> l >> r;

		int first = lower_bound(len_pref.begin(), len_pref.end(), l) - len_pref.begin();
		if (len_pref[first] == l) 

	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    