#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<int> x_sort(n), y_sort(n);
    iota(x_sort.begin(), x_sort.end(), 0);
    iota(y_sort.begin(), y_sort.end(), 0);

    sort(x_sort.begin(), x_sort.end(), [&](int a, int b) {
        return x[a] < x[b];
    });
    sort(y_sort.begin(), y_sort.end(), [&](int a, int b) {
        return y[a] < y[b];
    });

    vector<bool> x_l(n), y_l(n);

    for (int i = 0; i < n / 2; i++) {
        x_l[x_sort[i]] = true;
        y_l[y_sort[i]] = true;
    }


    vector<int> a, b, c, d;
    for (int i = 0; i < n; i++) {
        if (x_l[i] && y_l[i]) a.push_back(i);
        else if (!x_l[i] && !y_l[i]) b.push_back(i);
        else if (x_l[i] && !y_l[i]) c.push_back(i);
        else d.push_back(i);
    }

    assert(sz(a) == sz(b) && sz(c) == sz(d));
    for (int i = 0; i < sz(a); i++) cout << a[i] + 1 << " " << b[i] + 1 << "\n";
    for (int i = 0; i < sz(c); i++) cout << c[i] + 1 << " " << d[i] + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    