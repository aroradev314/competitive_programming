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

void solve() {
    ll g, w, l;
    cin >> w >> g >> l;
    
    mint times = w - g;
    mint each = mint(2LL) + mint(2 * l - 1);
    mint ans = times * each;

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
