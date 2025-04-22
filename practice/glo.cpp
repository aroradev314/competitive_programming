#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 2e5 + 10;
int a[MAX_N];
int lis[MAX_N];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int rep = 0; rep < 2; rep++) {
    	Tree<int> s;
    	s.insert(a[n - 1]);
    	lis[n - 1] = 1;
    	for (int i = n - 2; i >= 0; i--) {
    		auto it = s.upper_bound(a[i]);
    		if (it == s.begin()) {
    			s.insert(a[i]);
    		}
    		else {
    			it--;
    			s.erase(it);
    			s.insert(a[i]);
    		}
			lis[i] = sz(s) - s.order_of_key(a[i]);
			ans = max(ans, lis[i]);
    	}

    	vector<int> dp = {a[0]};
    	for (int i = 1; i < n; i++) {
    		int pos = lower_bound(dp.begin(), dp.end(), a[i] + x) - dp.begin();
    		ans = max(ans, pos + lis[i]);
    		pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    		if (pos == sz(dp)) dp.push_back(a[i]);
    		else dp[pos] = a[i];
    	}

    	reverse(a, a + n);
    	for (int i = 0; i < n; i++) a[i] = -a[i];
    }
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    