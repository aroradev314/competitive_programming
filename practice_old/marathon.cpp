#include <vector>
#include <iostream>
#define ll long long
using namespace std;

struct sumtree {
	vector<ll> segtree;
	vector<pair<int, int>> pos;
	sumtree(vector<pair<int, int>>& positions) {
		pos = positions;
		segtree.resize(2 * n);
	{
	void updateBoth(int i, int x, int y) {
		pos[i] = {x, y};
		update(0, 
	// v is current vertex, n is new value, x is intended position
	void update(int v, int n, int p, int tl, int tr) {
		if (tl == tr && tl == p) {
			segtree[v] = n;
			return;
		}
		int middle = (tl + tr) / 2;
		if (x <= middle) {
			update(v * 2, p, x, tl, middle);
		}
		else {
			update(v * 2 + 1, p, x, middle + 1, tr);
		}
		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
	}
	ll query(int v, int tl, int tr, int l, int r) {
		if (l <= tl && tr <= r) {
			return segtree[v];
		}
		int middle = (tl + tr) / 2;
		ll ans = 0;
		if (l <= middle) {
			ans += query(v * 2, tl, middle, l, r);
		}
		if (r > middle) {
			ans += query(v * 2 + 1, middle + 1, tr, l, r);
		}
		return ans;
	}
};

ll distance(int x1, int y1, int x2, int y2) {
	return abs((ll)(x2) - x1) + abs((ll)(y2) - y1);
}


int main() {
	int n, q;
	cin >> n >> q;
	
	vector<pair<int, int>> points(n);
	
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	sumtree t1(n);
	for (int i = 0; i < n; i++) {
		update(0, distance(
		
}

	
	
	
