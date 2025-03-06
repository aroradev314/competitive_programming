#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

template <typename T>
struct SegTree {
    int n;                // size of the array
    std::vector<T> seg;     // segment tree array
    T neutral;            // neutral element for the operation
    std::function<T(T, T)> cmb;  // commutative binary operation

    SegTree(int size, T neutral_elem, std::function<T(T, T)> operation)
        : n(size), seg(4 * size, neutral_elem), neutral(neutral_elem), cmb(operation) {}


    void build(vector<T>& a, int v, int tl, int tr) {
    	if (tl == tr) seg[v] = a[tl];
    	else {
    		int mid = (tl + tr) / 2;
    		build(a, 2 * v, tl, mid);
    		build(a, 2 * v + 1, mid + 1, tr);
    		seg[v] = cmb(seg[2 * v], seg[2 * v + 1]);
    	}
    }

    T query(int v, int tl, int tr, int l, int r) {
    	if (l > r) return neutral;
    	if (tl == l && tr == r) return seg[v];

    	int tm = (tl + tr) / 2;

    	return cmb(query(v * 2, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void update(int tl, int tr, int v, int pos, T new_val) {
    	if (tl == tr) seg[v] = new_val;
    	else {
    		int tm = (tl + tr) / 2;
    		if (pos <= tm) update(tl, tm, 2 * v, pos, new_val);
    		else {
    			update(tm + 1, tr, 2 * v + 1, pos, new_val);
    		}
    		seg[v] = cmb(seg[2 * v], seg[2 * v + 1]);
    	}
    }
};

const int INF = 2e9;

struct Info {
	int mn1, mn2, mx1, mx2, ans1, ans2;

	Info() : mn1(INF), mn2(INF), mx1(0), mx2(0), ans1(0), ans2(0) {}
	Info(int x, int y) : mn1(x), mn2(y), mx1(x), mx2(y), ans1(0), ans2(0) {}
};

Info add(const Info a, const Info b) {
	Info ret;
	ret.mn1 = min(a.mn1, b.mn1);
	ret.mn2 = min(a.mn2, b.mn2);
	ret.mx1 = max(a.mx1, b.mx1);
	ret.mx2 = max(a.mx2, b.mx2);
	ret.ans1 = max({a.ans1, b.ans1, b.mx1 - a.mn1}); // a[i] - i
	ret.ans2 = max({a.ans2, b.ans2, a.mx2 - b.mn2});
	return ret;
}

void solve() {
	int n, q;
	cin >> n >> q;

	Info neutral;
	SegTree<Info> seg(n, neutral, add);
	vector<Info> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = Info(x - i, x + i);
	}
	seg.build(a, 1, 0, n - 1);

	Info res = seg.query(1, 0, n - 1, 0, n - 1);
	cout << max(res.ans1, res.ans2) << "\n";

	while (q--) {
		int p, x;
		cin >> p >> x;
		p--;

		a[p] = Info(x - p, x + p);
		seg.update(0, n - 1, 1, p, a[p]);

		res = seg.query(1, 0, n - 1, 0, n - 1);

		cout << max(res.ans1, res.ans2) << "\n";	
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    