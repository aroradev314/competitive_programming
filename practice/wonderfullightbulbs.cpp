#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    map<int, int> col, diag;
    for (int i = 0; i < n; i++) {
    	col[x[i]]++;
    	diag[y[i] + x[i]]++;
    } 

    int xc = -1;
    for (auto [c, cnt] : col) {
    	if (cnt % 2 == 1) {
    		xc = c;
    		break;
    	}
    }
    assert(xc != -1);

    for (auto [diff, cnt] : diag) {
    	if (cnt % 2 == 1) {
    		cout << xc << " " << diff - xc << "\n";
    		return;
    	}
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    