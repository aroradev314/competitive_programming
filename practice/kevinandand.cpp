// #include <bits/stdc++.h>
// #define sz(a) ((int)((a).size()))
// typedef long long ll;
// typedef long double ld;
// using namespace std;

// const int MAX_N = 1e5 + 10;
// const int MAX_M = 11;
// int a[MAX_N];
// int b[MAX_M];
// int bits[1 << MAX_M];
// int comb[1 << MAX_M];
// int ops[MAX_N * MAX_M + 100];

// void solve() {
//     int n, m, x;
//     cin >> n >> m >> x;
//     ll asum = 0;
//     for (int i = 0; i < n; i++) {
//     	cin >> a[i];
//     	asum += a[i];
//     }
//     for (int i = 0; i < m; i++) cin >> b[i];

//     for (int i = 0; i < (1 << m); i++) {
//     	comb[i] = (1 << 30) - 1;
//     	for (int j = 0; j < m; j++) if ((1 << j) & i) comb[i] &= b[j];
//     }

// 	int c = 0;
//     for (int i : a) {
//     	vector<int> best(m + 1, i);
//     	for (int j = 0; j < (1 << m); j++) {
//     		int cur = i & comb[j];
//     		best[bits[j]] = min(best[bits[j]], cur);
//     	}
//     	for (int j = 0; j < m; j++) ops[c++] = best[j] - best[j + 1];
//     }
// 	sort(ops, ops + n * m);
	
// 	ll rem = 0;
// 	for (int i = 0; i < x; i++) {
// 		rem += ops[n * m - 1 - i];
// 	}

// 	cout << asum - rem << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// 	for (int i = 0; i < (1 << MAX_M) - 1; i++) bits[i] = __builtin_popcount(i);
//     int t;
//     cin >> t;
//     while (t--) solve();
// }
//     

#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), b(m), comb(1 << m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < (1 << m); i++) {
    	comb[i] = (1 << 30) - 1;
    	for (int j = 0; j < m; j++) if ((1 << j) & i) comb[i] &= b[j];
    }

    ll asum = 0;
    for (int i : a) asum += i;

    vector<int> ops;
    for (int i : a) {
    	vector<int> best(m + 1, i);
    	for (int j = 0; j < (1 << m); j++) {
    		int cur = i & comb[j];
    		int bits = __builtin_popcount(j);
    		best[bits] = min(best[bits], cur);
    	}
    	for (int j = 0; j < m; j++) ops.push_back(best[j] - best[j + 1]);
    }
	
	sort(ops.begin(), ops.end());
	ll rem = 0;
	for (int i = 0; i < x; i++) {
		rem += ops[n * m - 1 - i];
	}

	cout << asum - rem << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
