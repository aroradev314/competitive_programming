#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct Rand {
    mt19937_64 rng;
    uniform_int_distribution<uint64_t> dist;

    Rand() : dist(0, UINT64_MAX) {
        // Use high-resolution clock to seed the RNG
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        rng.seed(seed);
    }

    uint64_t next() {
        return dist(rng);
    }
};

void solve() {
    Rand rand;
    
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<uint64_t> pref(n + 1);
    map<int, uint64_t> hsh;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (!hsh.count(a[i])) hsh[a[i]] = rand.next();

        pref[i] = pref[i - 1] ^ (hsh[a[i]]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if ((pref[r] ^ pref[l - 1]) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
