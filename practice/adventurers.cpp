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
    vector<pair<int, int>> pts_x(n), pts_y(n);
    for (int i = 0; i < n; i++) {
    	cin >> pts_x[i].first >> pts_x[i].second;
    	pts_y[i] = pts_x[i];
    }

    sort(pts_x.begin(), pts_x.end());
    sort(pts_y.begin(), pts_y.end(), [](pair<int, int>& a, pair<int, int>& b) {
    	return a.second < b.second;
    });

    int ans = 0;
    int cur = n - 1;

    Tree<pair<int, int>> left_pts, right_pts; // y, index
    for (int i = 0; i < n; i++) left_pts.insert({pts_x[i].second, i});

    int x = -1, y = -1;
    while (cur >= 0) {
    	left_pts.erase({pts_x[cur].second, cur});
    	right_pts.insert({pts_x[cur].second, cur});
    	cur--;
    	while (cur >= 0 && pts_x[cur].first == pts_x[cur + 1].first) {
	    	left_pts.erase({pts_x[cur].second, cur});
	    	right_pts.insert({pts_x[cur].second, cur});
	    	cur--;
    	}
    	// cout << "left\n";
    	// for (auto i : left_pts) cout << i.first << " ";
    	// cout << endl;
    	// cout << "right\n";
    	// for (auto i : right_pts) cout << i.first << " ";
    	// cout << endl << endl;

    	// if (sz(right_pts) == 2) cout << right_pts.order_of_key({2, 0});


    	int l = -1e9, r = 1e9;
    	while (l <= r) {
    		int mid = l + (r - l) / 2;
    		// if (sz(right_pts) == 2) cout << mid << endl;

    		int bottom_left_pts = left_pts.order_of_key({mid, 0});
    		int bottom_right_pts = right_pts.order_of_key({mid, 0});
    		int top_left_pts = sz(left_pts) - bottom_left_pts;
    		int top_right_pts = sz(right_pts) - bottom_right_pts;

    		int cand = min({bottom_left_pts, bottom_right_pts, top_left_pts, top_right_pts});
    		if (cand > ans) {
    			ans = cand;
    			x = pts_x[cur + 1].first;
    			y = mid;
    		}
    		if (cand == bottom_left_pts || cand == bottom_right_pts) l = mid + 1;
    		else r = mid - 1;
    	}
    }

    cout << ans << "\n";
    cout << x << " " << y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    