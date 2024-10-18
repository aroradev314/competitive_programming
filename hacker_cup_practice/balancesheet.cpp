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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n), x(n), y(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> x[i] >> y[i];
    
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int l, int m) {
        if (a[l] == a[m]) return (x[l] < x[m]);
        else return (a[l] < a[m]);
    });

    map<int, vector<int>> which; // for each sell day, put the indexes of that seller
    for (int i = 0; i < n; i++) {
        which[b[i]].push_back(i);
    }
    for (auto& [b_val, v] : which) {
        sort(v.begin(), v.end(), [&](int l, int m) {
            return y[l] < y[m]; // sort indexes buy how much each is selling for 
        });
    }

    vector<multiset<ll>> each(n); // store the k biggest paths ending at i
    multiset<ll> cur; // k best for this buy day
    int day = -1, pointer = -1;
    vector<int> candidates;
    for (int i : ind) {
        // find all y values with b == i that are less, and add them to cur
        if (a[i] != day) {
            day = a[i];
            cur.clear();
            pointer = 0;
            if (which.count(day)) candidates = which[day];
            else candidates.clear();
        }
        while (pointer < sz(candidates) && y[candidates[pointer]] < x[i]) {
            // cout << candidates[pointer] << " " << a[candidates[pointer]] << "\n";
            // cout << sz(each[candidates[pointer]]) << "\n";
            // cout << x[i] << "\n";
            for (ll j : each[candidates[pointer]]) cur.insert(-y[candidates[pointer]] + j);
            pointer++;
        }
        if (sz(cur) < k) {
            for (ll j : cur) each[i].insert(j + x[i]);
            each[i].insert(0);
        }
        else {
            auto it = --cur.end();
            for (int j = 0; j < k; j++) {
                each[i].insert(*it + x[i]);
                it--;
            }
        }
        // cout << i + 1 << "\n";
        // for (ll j : each[i]) cout << j << " ";
        // cout << "\n\n";
    }

    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        for (ll j : each[i]) pq.push(j);
    }

    mint ans = 0LL;
    for (int i = 0; i < k && sz(pq); i++) {
        ans += pq.top();
        pq.pop();
    }

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
