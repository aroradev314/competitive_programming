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

const int MAX_N = 3e5 + 10;
int h[MAX_N];
int b[MAX_N];
ll dp[MAX_N];

ll INF = 1e16;

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	auto op = [](ll x, ll y) {
		return max(x, y);
	};

	SegTree<ll> seg(n + 1, -INF, op);
	dp[0] = 0;
	seg.modify(0, 0LL);

	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		while (h[s.top()] >= h[i]) s.pop();
		dp[i] = seg.query(s.top(), i - 1) + b[i];
		if (s.top() > 0) dp[i] = max(dp[i], dp[s.top()]);
		seg.modify(i, dp[i]);
		s.push(i);
	}
	cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    