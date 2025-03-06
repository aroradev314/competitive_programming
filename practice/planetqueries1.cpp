#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
const int LOG = 31;

int up[MAX_N][LOG];
int t[MAX_N];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		t[i]--;
	}

	for (int i = 0; i < LOG; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) up[j][i] = t[j];
			else up[j][i] = up[up[j][i - 1]][i - 1];
		}
	}

	while (q--) {
		int x, k;
		cin >> x >> k;
		x--;

		for (int i = LOG - 1; i >= 0; i--) {
			if (k & (1 << i)) x = up[x][i];
		}
		cout << x + 1 << "\n";
	}


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) solve();
}
    