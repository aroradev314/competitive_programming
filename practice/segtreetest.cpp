#include <bits/stdc++.h>
#include <functional>
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
        for (t[p += n] += value; p > 1; p >>= 1) 
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
    cin >> n;
    SegTree<ll> seg(n, 0, plus<ll>());

    for (int i = 0; i < n; i++) cin >> seg.t[i + n];
    seg.build();

    int q;
    cin >> q;

    while (q--) {
        char t;
        cin >> t;

        if (t == 'q') {
            int l, r; 
            cin >> l >> r;
            l--; r--;
            cout << seg.query(l, r) << "\n";
        }
        else {
            int i, x;
            cin >> i >> x;
            i--;

            seg.modify(i, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
