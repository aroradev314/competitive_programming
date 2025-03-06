#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 200010;
int d[MAX_N];
map<int, int> factor[MAX_N];
int a[100010];
vector<int> seen[MAX_N];

void solve() {
	for (int i = 2; i < MAX_N; i++) {
		if (d[i] == 0) for (int j = i; j < MAX_N; j += i) d[j] = i;
	}

	for (int i = 2; i < MAX_N; i++) {
		factor[i][d[i]]++;
		for (auto [fac, pow] : factor[i / d[i]]) factor[i][fac] += pow;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (auto [fac, pow] : factor[a[i]]) seen[fac].push_back(pow);
	}
	
	ll ans = 1;
	for (int i = 2; i < MAX_N; i++) {
		if (sz(seen[i]) < n) seen[i].push_back(0);
		if (sz(seen[i]) < n) seen[i].push_back(0);
		sort(seen[i].begin(), seen[i].end());
		for (int j = 0; j < seen[i][1]; j++) ans *= i;
	}
	
	cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    