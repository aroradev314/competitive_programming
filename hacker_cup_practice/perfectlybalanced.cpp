#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct Rand {
    mt19937_64 rng;
    uniform_int_distribution<ll> dist;

    Rand() : dist(0, LONG_LONG_MAX) {
        // Use high-resolution clock to seed the RNG
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        rng.seed(seed);
    }

    ll next() {
        return dist(rng);
    }
};

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

const int MAX_N = 1e6;
ll id[MAX_N + 10];
int a[MAX_N + 10];
map<ll, int> rev;

const ll MOD = (1LL << 61) - 1;

void solve() {
    int n;
    cin >> n;

    auto op = [](ll x, ll y) {
        return (x + y) % MOD;
    };

    SegTree<ll> seg(n, 0LL, op);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        ll val = id[x];
        seg.t[n + i] = val;
    }
    seg.build();
    
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            x--;

            a[x] = y;
            seg.modify(x, id[y]);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            if (l % 2 != r % 2) continue;
            else if (l == r) {
                ans++;
            }
            else {
                int mid = (l + r) / 2;
                bool works = false;

                ll first = seg.query(l, mid), second = seg.query(mid + 1, r);
                ll diff = first - second;
                if (diff < 0) diff += MOD;
                if (rev.count(diff)) works = true;

                first = seg.query(l, mid - 1), second = seg.query(mid, r);
                diff = second - first;
                if (diff < 0) diff += MOD;
                if (rev.count(diff)) works = true;

                if (works) ans++;


            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    
    Rand rand;
    for (int i = 1; i <= MAX_N; i++) {
        ll x = rand.next() % MOD;
        id[i] = x;
        rev[x] = i;
    }

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
