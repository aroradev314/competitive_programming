#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];

	sort(a.begin(), a.end());
	deque<int> d;
	for (int i : a) d.push_back(i);

	for (int i = 0; i < n; i += 2) {
		int x = d.front();
		int y = d.back();
		d.pop_front();
		if (sz(d)) d.pop_back();

		for (int j = 0; j < 3; j++) cout << x << " " << y << " ";
		cout << "\n";

		if (i != n - 1) {
			for (int j = 0; j < 3; j++) cout << y << " " << x << " ";
			cout << "\n";
		}
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    