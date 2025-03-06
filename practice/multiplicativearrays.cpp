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

const int MOD = 998244353;
typedef ModularInt<MOD> mint;

const int MAX_N = 1e5 + 10;
int p[MAX_N];
int num[MAX_N];
mint fac[MAX_N];
map<int, int> primes[MAX_N];

mint choose_big(int a, int b) {
	if (a < b) return (mint) 0;
	return fac[a] / (fac[b] * fac[a - b]);
}

mint choose(int a, int b) {
	if (a < b) return (mint) 0;
	mint ans = 1;
	for (int i = 0; i <= b - 1; i++) ans *= ((mint) a - (mint) i) / ((mint) i + 1);
	return ans;
}

mint pow(mint a, int b) {
	mint ans = 1;
	for (int i = 0; i < b; i++) ans *= a;
	return ans;
}

void solve() {
	int k, n;
	cin >> k >> n;

	cout << n << " ";
	for (int i = 2; i <= k; i++) {
		int most = min((int) n, (int) num[i]);
		vector<mint> dp(most + 1); // dp[j] is how many ways that we can make i using j elements that are greater than 1
		mint ans = 0;
		for (int j = 1; j <= most; j++) {
			mint cur = 1;
			for (auto [x, val] : primes[i]) cur *= choose_big(val + j - 1, j - 1);
			for (int x = 1; x < j; x++) cur -= choose_big(j, x) * dp[x];
			dp[j] = cur;
			ans += dp[j] * choose((n - j) + (j + 2) - 1, (j + 2) - 1);
		}
		cout << ans << " ";
	}

	cout << "\n";
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    for (int i = 2; i < MAX_N; i++) {
    	if (p[i] == 0) {
    		for (int j = i; j < MAX_N; j += i) p[j] = i;
    	}
    }

    for (int i = 2; i < MAX_N; i++) {
    	num[i] = 1 + num[i / p[i]];
    	primes[i] = primes[i / p[i]];
    	primes[i][p[i]]++;
    }

    fac[0] = (mint) 1;
	for (int i = 1; i < MAX_N; i++) fac[i] = (mint) (i) * fac[i - 1];

    int t;
    cin >> t;
    while (t--) solve();
}
    