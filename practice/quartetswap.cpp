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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    vector<int> even, odd;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) even.push_back(a[i]);
		else odd.push_back(a[i]);
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	reverse(even.begin(), even.end());
	reverse(odd.begin(), odd.end());

	Tree<int> t;
	int inv = 0;
	for (int i = 0; i < n; i++) {
		inv += sz(t) - t.order_of_key(a[i]);
		t.insert(a[i]);
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			ans.push_back(even.back());
			even.pop_back();
		}
		else {
			ans.push_back(odd.back());
			odd.pop_back();
		}
	}


	Tree<int> c;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += sz(c) - c.order_of_key(ans[i]);
		c.insert(ans[i]);
	}

	if (cur % 2 != inv % 2) swap(ans[n - 1], ans[n - 3]);

	for (int i : ans) cout << i + 1 << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    