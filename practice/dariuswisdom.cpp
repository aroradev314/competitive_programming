#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int one = -1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 1) {
			one = i;
			break;
		}
	}

	vector<pair<int, int>> ans;
	int r = n - 1;
	while (a[r] == 2) r--;

	if (a[r] == 0) {
		ans.push_back({one, r});
		a[r]++;
		a[one]--;
	}

	set<int> ones, zeros;
	ones.insert(r);

	int x;
	for (int i = r - 1; i >= 0; i--) {
		if (a[i] == 0) zeros.insert(i);
		else if (a[i] == 1) {
			if (sz(zeros)) {
				x = *(--zeros.end());
				ans.push_back({i, x});
				zeros.erase(x);
				ones.insert(x);
				zeros.insert(i);
			}
		}
		else {
			if (sz(ones)) {
				x = *(--ones.end());
				ans.push_back({i, x});
				ones.erase(x);
				ones.insert(i);

				if (sz(zeros)) {
					x = *(--zeros.end());
					ans.push_back({i, x});
					zeros.erase(x);
					ones.erase(i);
					ones.insert(x);
					zeros.insert(i);
				}
			}
		}
	}

	assert(sz(ans) <= n);
	cout << sz(ans) << "\n";
	for (auto i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    