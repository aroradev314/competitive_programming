#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 

    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> c;
	
	int h = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			c.push_back(i);
			a[i] = 0;
		}
		else if (a[i] == 1) h++;

		while (h < l[i]) {
			if (sz(c) == 0) {
				cout << "-1\n";
				return;
			}
			a[c.back()] = 1;
			h++;
			c.pop_back();
		}
	}

	h = 0;
	for (int i = 0; i < n; i++) {
		h += a[i];
		if (h < l[i] || h > r[i]) {
			cout << "-1\n";
			return;
		}
	}

	for (int i : a) cout << i << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    