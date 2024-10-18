#include <vector>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<pair<int, int>> r(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i].first >> r[i].second;
	}
	sort(r.begin(), r.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
	
	
	ordered_set st;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += st.order_of_key(p.first);
		st.insert(p.first);
	}
	
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

