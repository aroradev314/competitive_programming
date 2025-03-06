#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    if (n == k) {
    	bool found = false;
    	for (int i = 1; i < n; i++) if (s[i] != s[0]) found = true;
    	cout << (found ? -1 : 1) << "\n";
    	return;
    }

    vector<int> left(n + 1, -1), right(n + 1, -1), suffix(n + 1);
    left[1] = 1;
    for (int i = 2; i <= n; i++) {
    	char c = s[i - 1], last = s[i - 2];
    	if ((c == last && left[i - 1] == 0) || (c != last && left[i - 1] != 0)) break;
    	left[i] = (left[i - 1] + 1) % k;
    }

    bool found = false;
    int val = 0;
    right[n] = 1, suffix[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
    	char c = s[i - 1], last = s[i];
    	if (!found) {
    		if (c != last) {
    			found = true;
    			suffix[i] = suffix[i + 1];
    			right[i] = 1;
    		}
    		else {
    			suffix[i] = suffix[i + 1] + 1;
    			if (right[i] + 1 > k
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
    