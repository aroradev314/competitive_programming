#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 2) {
    	cout << (s == "AB" ? "Alice" : "Bob") << "\n";
    	return;
    }
    if (s[0] == s[n - 1]) {
    	cout << (s[0] == 'A' ? "Alice" : "Bob") << "\n";
    }
    else if (s[0] == 'B') {
    	cout << (s[n - 2] == 'B' ? "Bob" : "Alice") << "\n";
    }
    else {
    	bool found = false;
    	for (int i = 1; i < n - 1; i++) if (s[i] == 'B') {
    		found = true;
    		break;
    	}
    	cout << (found ? "Bob" : "Alice") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    