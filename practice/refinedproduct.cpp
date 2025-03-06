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
	int n, q;
	cin >> n >> q;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<int> a_ind(n), b_ind(n);
	iota(a_ind.begin(), a_ind.end(), 0);
	iota(b_ind.begin(), b_ind.end(), 0);

	sort(a_ind.begin(), a_ind.end(), [&](int x, int y) {
		return a[x] < a[y];
	});

	sort(b_ind.begin(), b_ind.end(), [&](int x, int y) {
		return b[x] < b[y];
	});

	// sort(a.begin(), a.end());
	// sort(b.begin(), b.end());

	// now indices are sorted, and we know where each 
	// a_ind[x] means what original index is at position x when sorted
	// which_a[x] means where position x is in a_ind

	vector<int> which_a(n), which_b(n);
	for (int i = 0; i < n; i++) which_a[a_ind[i]] = i;
	for (int i = 0; i < n; i++) which_b[b_ind[i]] = i;

	// for (int i = 0; i < n; i++) cout << a_ind[i] << " ";
	// cout << endl;
	// for (int i = 0; i < n; i++) cout << b_ind[i] << " ";
	// cout << endl;

	mint ans = 1;
	for (int i = 0; i < n; i++) ans *= (mint) min(a[a_ind[i]], b[b_ind[i]]);

	cout << ans << " ";

	while (q--) {
		int o, pos;
		cin >> o >> pos;
		pos--;

		if (o == 1) {
			int x = which_a[pos];

			int l = x, r = n - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (a[a_ind[mid]] == a[a_ind[x]]) l = mid + 1;
				else r = mid - 1;
			}
			swap(a_ind[x], a_ind[l - 1]);
			swap(which_a[a_ind[x]], which_a[a_ind[l -1]]);

			mint before = min(a[a_ind[l - 1]], b[b_ind[l - 1]]);
			a[a_ind[l - 1]]++;
			mint after = min(a[a_ind[l - 1]], b[b_ind[l - 1]]);

			ans /= before;
			ans *= after;
		}
		else {
			int x = which_b[pos];

			int l = x, r = n - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (b[b_ind[mid]] == b[b_ind[x]]) l = mid + 1;
				else r = mid - 1;
			}
			swap(b_ind[x], b_ind[l - 1]);
			swap(which_b[b_ind[x]], which_b[b_ind[l - 1]]);

			mint before = min(a[a_ind[l - 1]], b[b_ind[l - 1]]);
			b[b_ind[l - 1]]++;
			mint after = min(a[a_ind[l - 1]], b[b_ind[l - 1]]);

			ans /= before;
			ans *= after;
		}
		cout << ans << " ";
	}
	cout << "\n";

	// for (int i : a) cout << i << " ";
	// cout << endl;""


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    