#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

  	if (n < 60 && (1LL << (n - 1)) < k) {
  		cout << "-1\n";
  		return;
  	}
  	k--; // 0 is the first permutation 

  	vector<int> perm(n, -1);
  	int l = 0, r = n - 1;
  	for (int i = 1; i <= n; i++) {
  		int dist = n - i - 1;
  		if (i == n) perm[l] = i;
  		if (dist < 60 && (k & (1LL << dist))) {
  			perm[r--] = i;
  		}
  		else perm[l++] = i;
  	}

  	for (int i : perm) cout << i << " ";
  	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    