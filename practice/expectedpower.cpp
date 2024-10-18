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

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<mint> p(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] = p[i] / mint((ll) 1e4);
    }
    
    vector<mint> dp(1024), ndp(1024);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        // probability of getting j on the i'th turn
        // either we get a[i] on this turn and we need j ^ a[i]
        // or we don't get a[i] and so then its just the probability of the last time
        for (int j = 0; j < 1024; j++) ndp[j] = p[i] * dp[j ^ a[i]] + (mint(1) - p[i]) * dp[j];
        dp = ndp;
    }

    mint ans = 0;
    for (int i = 0; i < 1024; i++) ans += mint(i) * mint(i) * dp[i];
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
