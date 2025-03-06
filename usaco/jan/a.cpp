#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
using namespace std;

const int MAX_N = 5e5 + 10;
int over[MAX_N];
ll rem[MAX_N];
priority_queue<int> pq[MAX_N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = n - i;
		while (sz(pq[a[i]]) && pq[a[i]].top() >= left) {
			over[a[i]]++;
			rem[a[i]] -= (pq[a[i]].top() + 1);
			pq[a[i]].pop();
		}
		ans += over[a[i]] * 1LL * (left + 1);
		ans += rem[a[i]];

		pq[b[i]].push(i - 1);
		rem[b[i]] += i;
	}
	for (int i = 1; i <= n; i++) {
		over[i] = 0;
		rem[i] = 0;
		while (sz(pq[i])) pq[i].pop();
	}

	for (int i = n; i >= 1; i--) {
		int left = i - 1;

		while (sz(pq[a[i]]) && pq[a[i]].top() >= left) {
			over[a[i]]++;
			rem[a[i]] -= (pq[a[i]].top() + 1);
			pq[a[i]].pop();
		}
		ans += over[a[i]] * 1LL * (left + 1);
		ans += rem[a[i]];

		pq[b[i]].push(n - i);
		rem[b[i]] += n - i + 1;
	}

    for (int i = 1; i <= n; i++) {
    	if (a[i] == b[i]) {
    		ll before = i - 1;
    		ll after = n - before - 1;
    		ans += (before * (before + 1)) / 2;
    		ans += (after * (after + 1)) / 2;
    		ans += min(before, after) + 1;
    	}
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
    