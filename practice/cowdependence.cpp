#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans(n + 1);
	vector<int> last(n + 1, -1), last_pos(n + 1, -1);

	for (int i = 0; i < n; i++) {
		if (last[a[i]] == -1) {
			ans[0]++;
		}
		else {
			last_pos[i] = last[a[i]];
			int dist = i - last_pos[i];
			ans[0]++;
			ans[dist]--;

			int before = last_pos[last_pos[i]];
			if (before != -1) {
				ans[dist]++;
				int long_dist = i - before;
				ans[long_dist]--;
			}
		}
		
		last[a[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
		cout << ans[i] << " ";
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    