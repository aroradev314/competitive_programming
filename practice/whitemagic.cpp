#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int a[MAX_N];
int mn[MAX_N];
bool seen[MAX_N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int left = -1;
	
	int non = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (left == -1) left = i;
		}
		else non++;
	}

	int ans = max(1, non);
	if (left != -1) {
		for (int i = 0; i <= n + 5; i++) seen[i] = false;
		for (int i = left; i < n; i++) if (a[i] < MAX_N) seen[a[i]] = true;
		int mex = 0;
		while (seen[mex]) mex++;
		mn[0] = a[0];
		for (int i = 1; i < n; i++) mn[i] = min(mn[i - 1], a[i]);

		bool works = true;
		for (int i = left; i > 0; i--) {
			if (a[i] < MAX_N) seen[a[i]] = true;
			while (seen[mex]) mex++;
			if (mex > mn[i - 1]) {
				works = false;
				break;
			}
		}

		if (works) ans = non + 1;
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
    