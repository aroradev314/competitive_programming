#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int t[MAX_N];
int indeg[MAX_N];
int idx[MAX_N];
int col[MAX_N];
int cycle[MAX_N];

void solve() {
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> t[i];
		t[i]--;
		indeg[t[i]]++;
	}

}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tt = 1;
    while (tt--) solve();
}
    