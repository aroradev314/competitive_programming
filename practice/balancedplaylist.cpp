#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree {
    const T ID{};
    function<T(T, T)> cmb;
    int n;
    vector<T> t;

    SegTree(int _n, function<T(T, T)> _cmb) : n(2 * _n + 10), t(n), cmb(_cmb) {}

    void build() {
        for (int i = n - 1; i >= 0; i--) t[i] = cmb(t[i<<1], t[i<<1|1]);
    }

    void modify(int p, T value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = cmb(t[p], t[p^1]);
    }

    int query(int l, int r) {  // sum on interval [l, r]
        T res = ID;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = cmb(res, t[l++]);
            if (r&1) res = cmb(res, t[--r]);
        }
        return res;
    }
};

bool lesser(int a, int x) {
    return (a < (x / 2 + x % 2));
}

int main() {
    auto mn = [](int a, int b) { return min(a, b); };
    SegTree<int> sg(1, mn);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    int mxpos = 0;
    for (int i = 1; i < n; i++) if (a[i] > a[mxpos]) mxpos = i;

    vector<int> time(n, -1);

    
    for (int i = 1; i < n; i++) {
        int id = (mxpos + i) % n;
        if (lesser(a[id], a[mxpos])) {
            time[mxpos] = i;
            break;
        }
    }

    // binary search over next time that we see a guy less than x / 2, if we see him before we see someone 
    // greater then it will be that, otherwise it will be 
    
    for (int i = 1; i < n; i++) {
        int id = mxpos - i;
        if (id < 0) id += n;
        int nxt = (id + 1) % n;


    }
}

