#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int big = 0;
    for (int i = 0; i < n - 1; i++) if (s[i] == '>') big++;
    int lo = n - big, hi = n - big;
	
	cout << lo << " ";
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '>') cout << (++hi) << " ";
		else cout << (--lo) << " ";
	}

	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    