#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= m;
	}

	sort(a.begin(), a.end());

	vector<ll> num, freq;
	num.push_back(a[0]);
	freq.push_back(1);

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) freq.back()++;
		else {
			num.push_back(a[i]);
			freq.push_back(1);
		}
	}

	n = sz(num);
	vector<ll> ans(n);

	int pt = 0;
	ll bef = 0, bef_num = 0;
	ll pref = 0, pref_num = 0;
	for (int i = 0; i < n; i++) {
		while (pt < i && m - (num[i] - num[pt]) < num[i] - num[pt]) {
			bef += freq[pt];
			bef_num += freq[pt] * num[pt];
			pref -= freq[pt];
			pref_num -= freq[pt] * num[pt];
			pt++;
		}
		ans[i] += (num[i] * pref) - pref_num;
		ans[i] += bef_num + ((m - num[i]) * bef);

		pref += freq[i];
		pref_num += freq[i] * num[i];
	}

	bef = 0, bef_num = 0;
	pref = 0, pref_num = 0;
	pt = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		while (pt > i && m - (num[pt] - num[i]) < num[pt] - num[i]) {
			bef += freq[pt];
			bef_num += freq[pt] * (m - num[pt]);
			pref -= freq[pt];
			pref_num -= freq[pt] * num[pt];
			pt--;
		}
		ans[i] += pref_num - (num[i] * pref);
		ans[i] += bef_num + (num[i] * bef);

		pref += freq[i];
		pref_num += freq[i] * num[i];
	}

	ll best = ans[0];
	for (int i = 1; i < n; i++) best = min(best, ans[i]);

	cout << best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    