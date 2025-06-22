#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

template <typename T>
struct SegTree {
    int n;                // size of the array
    std::vector<T> t;     // segment tree array
    T neutral;            // neutral element for the operation
    std::function<T(T, T)> op;  // commutative binary operation

    SegTree(int size, T neutral_elem, std::function<T(T, T)> operation)
        : n(size), t(2 * size, neutral_elem), neutral(neutral_elem), op(operation) {}

    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) 
            t[i] = op(t[i<<1], t[i<<1|1]);
    }

    void modify(int p, T value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) 
            t[p>>1] = op(t[p], t[p^1]);
    }

    T query(int l, int r) {  // query the operation result on the interval [l, r]
        T res = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = op(res, t[l++]);
            if (r&1) res = op(res, t[--r]);
        }
        return res;
    }
};

void solve() {
    int n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    for (int i = 1; i <= n; i++) cin >> b[i]; 

    vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) p[i] = a[i] - b[i];

	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) pref[i] = pref[i - 1] + p[i];

	auto op = [](ll a, ll b) {
		return min(a, b);
	}

	SegTree seg(n + 2, LLONG_MAX, op);
	for (int i = 1; i < n; i++) seg.t[n + 1 + i] = 

	// the sum from i to i + j, is pref[i] - pref[i + j + 1]
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    