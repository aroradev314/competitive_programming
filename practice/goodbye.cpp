#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> t = {k};
    for (int i = 2; i <= n; i++) {
    	vector<int> x;
    	for (int j = 1; j <= i; j++) {
    		if (j == 1) x.push_back(t[j - 1]);
    		else if (j == i) x.push_back(t[j - 2]);
    		else x.push_back(t[j - 1] ^ t[j - 2]);
    	}
    	t = x;
    	for (int j : t) cout << j << " ";
    	cout << endl;
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    