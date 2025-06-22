#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;


template<int MODULO>
struct ModularInt {
    int value;

    ModularInt() : value(0) {}  // Initializes value to 0
 
    ModularInt(ll llvalue) : value(llvalue % MODULO) {
        if (value < 0) {
            value += MODULO;
        }
    }
 
    ModularInt(const ModularInt<MODULO>& other) : value(other.value) {}
 
    inline void operator+=(ModularInt<MODULO> other) {
        value += other.value;
        if (value >= MODULO) {
            value -= MODULO;
        }
    }
 
    inline ModularInt<MODULO> operator+(ModularInt<MODULO> other) const {
        return ModularInt<MODULO>(value + other.value >= MODULO ? value + other.value - MODULO : value + other.value);
    }
 
    inline void operator-=(ModularInt<MODULO> other) {
        value -= other.value;
        if (value < 0) {
            value += MODULO;
        }
    }
 
    inline ModularInt<MODULO> operator-(ModularInt<MODULO> other) const {
        return ModularInt<MODULO>(value - other.value < 0 ? value - other.value + MODULO : value - other.value);
    }
 
    inline ModularInt<MODULO> operator-() const {
        return ModularInt<MODULO>(value == 0 ? value : MODULO - value);
    }
 
    inline ModularInt<MODULO>& operator++() {
        ++value;
        if (value == MODULO) {
            value = 0;
        }
        return *this;
    }
 
    inline ModularInt<MODULO> operator++(int) {
        ModularInt<MODULO> old(*this);
        ++value;
        if (value == MODULO) {
            value = 0;
        }
        return old;
    }
 
    inline ModularInt<MODULO>& operator--() {
        --value;
        if (value == -1) {
            value = MODULO - 1;
        }
        return *this;
    }
 
    inline ModularInt<MODULO> operator--(int) {
        ModularInt<MODULO> old(*this);
        --value;
        if (value == -1) {
            value = MODULO - 1;
        }
        return old;
    }
 
    inline ModularInt<MODULO> operator*(ModularInt<MODULO> other) const {
        return ModularInt<MODULO>(1LL * value * other.value);
    }
 
    inline void operator*=(ModularInt<MODULO> other) {
        value = 1LL * value * other.value % MODULO;
    }
 
    friend ModularInt<MODULO> binpow(ModularInt<MODULO> a, ll bll) {
        if (a.value == 0) {
            return ModularInt<MODULO>(bll == 0 ? 1 : 0);
        }
        int b = bll % (MODULO - 1);
        int ans = 1;
        while (b) {
            if (b & 1) {
                ans = 1LL * ans * (int) a % MODULO;
            }
            a = 1LL * (int) a * (int) a % MODULO;
            b >>= 1;
        }
        return ModularInt<MODULO>(ans);
    }
 
    inline ModularInt<MODULO> inv() const {
        return binpow(*this, MODULO - 2);
    }
 
    inline ModularInt<MODULO> operator/(ModularInt<MODULO> other) const {
        return (*this) * other.inv();
    }
 
    inline void operator/=(ModularInt<MODULO> other) {
        value = 1LL * value * other.inv().value % MODULO;
    }
 
    inline bool operator==(ModularInt<MODULO> other) const {
        return value == other.value;
    }
 
    inline bool operator!=(ModularInt<MODULO> other) const {
        return value != other.value;
    }
 
    explicit operator int() const {
        return value;
    }
 
    explicit operator bool() const {
        return value;
    }
 
    explicit operator long long() const {
        return value;
    }
 
    friend istream& operator>>(istream& inp, ModularInt<MODULO>& mint) {
        ll input;
        inp >> input;
        mint = ModularInt<MODULO>(input);  // Use the constructor to set the value
        return inp;
    } 

    friend ostream& operator<<(ostream& out, const ModularInt<MODULO>& mint) {
        out << mint.value;
        return out;
    }
};

const int MOD = 1e9 + 7;
typedef ModularInt<MOD> mint;

const mint TWO = (mint) 2;

bool works;
int branch;
vector<vector<int>> adj;
vector<int> dp;
int first, second;

void dfs(int u, int p) {
	int c = sz(adj[u]) - (u != 0 ? 1 : 0);
	dp[u] = 1;

	if (c > 2) works = false;
	else if (c == 2) {
		if (branch != -1) works = false;
		else branch = u;
	}

	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		dp[u] += dp[v];
		if (u == branch) {
			if (first == -1) first = dp[v];
			else second = dp[v];
		}
	}
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n, vector<int>());
    dp.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b, a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    works = true;
    branch = -1;
    first = -1, second = -1;

    dfs(0, -1);

    if (!works) cout << "0\n";
    else if (branch == -1) {
    	cout << binpow(TWO, n) << "\n";
    }
    else {
    	mint ans;
    	if (first == second) ans = binpow(TWO, n - 2 * first + 1);
    	else ans = binpow(TWO, n - 2 * min(first, second) - 1) + binpow(TWO, n - 2 * min(first, second));
    	cout << ans << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    