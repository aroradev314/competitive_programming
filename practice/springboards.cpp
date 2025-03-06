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

const int INF = 2e9 + 10;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<array<int, 3>> pts;
    map<pair<int, int>, pair<int, int>> m;
    for (int i = 0; i < p; i++) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	pts.push_back({x1, y1, 0});
    	pts.push_back({x2, y2, 1});
    	m[{x2, y2}] = {x1, y1};
    } 
    pts.push_back({n, n, 0});
    sort(pts.begin(), pts.end());

    Tree<pair<int, int>> tree;
    map<pair<int, int>, int> dp;
    dp[{0, 0}] = 0;
    tree.insert({0, 0});

    for (auto [x, y, type] : pts) {
    	dp[{x, y}] = x + y;
    	if (type == 1) dp[{x, y}] = min(dp[{x, y}], dp[m[{x, y}]]);
    	auto best = *tree.find_by_order(tree.order_of_key({y + 1, 0}) - 1);
    	dp[{x, y}] = min(dp[{x, y}], x + y - best.second);

    	int spot = x + y - dp[{x, y}];
    	if (spot > best.second) {
    		while (tree.upper_bound({y, -1}) != tree.end() && (*tree.upper_bound({y, -1})).second < spot) tree.erase(tree.upper_bound({y, -1}));
    		tree.insert({y, x + y - dp[{x, y}]});
    	}
    }

    cout << dp[{n, n}];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    int t = 1;
    while (t--) solve();
}
    