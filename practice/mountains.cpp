#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct Frac {
	int a, b; // numerator and denominator

	Frac(int x, int y) : a(x), b(y) {}

	bool operator<(const Frac& other) {
		return (a * 1LL * other.b) < (b * 1LL * other.a);
	}

	bool operator<=(const Frac& other) {
		return (a * 1LL * other.b) <= (b * 1LL * other.a);
	}
};

const int MAX_N = 2020;
int h[MAX_N];
set<int> s[MAX_N];

// x to i1 is less than or equal to x to i2
bool comp(int x, int i1, int i2) {
	return Frac(h[i1] - h[x], i1 - x) <= Frac(h[i2] - h[x], i2 - x);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (j == i + 1) s[i].insert(j);
			else if (comp(i, *s[i].rbegin(), j)) s[i].insert(j);
		}
		ans += sz(s[i]);
	}

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--;
		h[x] += y;

		for (int i = 0; i < x; i++) {
			auto it = s[i].lower_bound(x);
			bool add = false;
			if (*it == x) {
				add = true;
				it++;
			}
			else {
				it--;
				if (comp(i, *it, x)) {
					add = true;
					s[i].insert(x);
					ans++;
				}
				it++;
				it++; // point to the element after
			}

			while (add && it != s[i].end() && !comp(i, x, *it)) {
				it = s[i].erase(it);
				ans--;
			}
		}

		ans -= sz(s[x]);
		s[x].clear();
		for (int j = x + 1; j < n; j++) {
			if (j == x + 1) s[x].insert(j);
			else if (comp(x, *s[x].rbegin(), j)) s[x].insert(j);
		}
		ans += sz(s[x]);

		cout << ans << "\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    