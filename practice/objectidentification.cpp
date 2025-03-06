#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n + 1);
	vector<bool> p(n + 1);

	bool same = true;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (x[i] != x[1]) same = false;
		p[x[i]] = true;
	}
	bool perm = true;
	for (int i = 1; i <= n; i++) if (!p[i]) perm = false;

	int ans;
	if (same) {
		int a = x[1];
		if (a == n) a--;
		else a++;

		cout << "? " << 1 << " " << a << endl;

		cin >> ans;
		if (ans == 0) cout << "! A" << endl;
		else cout << "! B" << endl;
	}
	else if (!perm) {
		int a = -1;
		for (int i = 1; i <= n; i++) if (!p[i]) a = i;
		int b = -1;
		for (int i = 1; i <= n; i++) if (x[i] != x[a]) b = i;

		cout << "? " << a << " " << b << endl;
		cin >> ans;
		if (ans == 0) cout << "! A" << endl;
		else cout << "! B" << endl;
	}
	else {
		int a = -1, b = -1;
		for (int i = 1; i <= n; i++) {
			if (x[i] == 1) a = i;
			else if (x[i] == n) b = i;
		}

		cout << "? " << a << " " << b << endl;
		cin >> ans;

		if (ans < n - 1) {
			cout << "! A" << endl;
		}
		else if (ans > n - 1) {
			cout << "! B" << endl;
		}
		else {
			cout << "? " << b << " " << a << endl;
			int ans2;
			cin >> ans2;
			if (ans2 == ans) cout << "! B" << endl;
			else cout << "! A" << endl;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

    