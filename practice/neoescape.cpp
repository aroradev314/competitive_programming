#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a = {-1};
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	if (x != a.back()) a.push_back(x);
    } 
  	a.push_back(-1);
    n = sz(a) - 2;

    map<int, vector<int>> pos;
    vector<int> vals;
    for (int i = 1; i <= n; i++) {
    	if (!pos.count(a[i])) vals.push_back(a[i]);
    	pos[a[i]].push_back(i);
    }

    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());

    vector<bool> on(n + 2);
    int ans = 0;
    for (int i : vals) {
    	for (int j : pos[i]) {
    		if (!on[j]) {
    			ans++;
    			on[j] = true;
    		}
    		on[j - 1] = true;
    		on[j + 1] = true;
    	}
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    