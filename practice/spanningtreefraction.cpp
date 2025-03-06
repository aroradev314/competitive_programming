#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 100100;
int U[MAX_N];
int V[MAX_N];
ld A[MAX_N];
ld B[MAX_N];

struct DSU {
    vector<int> pr;
    vector<int> siz;
    int n;
 
    DSU(int x) : n(x) {
        pr.resize(n);
        siz.resize(n, 1);
        iota(pr.begin(), pr.end(), 0);
    }
 
    inline int findpr(int v) {
        while (v != pr[v]) v = pr[v];
        return v;
    }
 
    inline bool unite(int v, int u) {
        v = findpr(v);
        u = findpr(u);

        if (siz[u] < siz[v]) swap(u, v);

        if (u == v) {
            return false;
        } else {
            pr[v] = u;
            siz[u] += siz[v];
            return true;
        }
    }
};

int gcd(int a, int b) {
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> U[i] >> V[i] >> A[i] >> B[i];
	}

	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);

	ld l = 0, r = 1e9;
	int ansa = 0, ansb = 0;
	for (int i = 0; i < 60; i++) {
		ld C = (l + r) / 2;
		DSU dsu(n);

		sort(ord.begin(), ord.end(), [&](int x, int y) {
			return ((ld) A[x] - B[x] * C) > ((ld) A[y] - B[y] * C);
		});
		int cura = 0, curb = 0;
		ld tot = 0;

		for (int id : ord) {
			bool status = dsu.unite(U[id], V[id]);
			if (status) {
				tot += (ld) A[id] - B[id] * C;
				cura += A[id];
				curb += B[id];
			}
		}

		if (tot >= 0) {
			ansa = cura;
			ansb = curb;
			l = C;
		}
		else r = C;
	}

	int g = gcd(ansa, ansb);
	ansa /= g;
	ansb /= g;

	cout << ansa << "/" << ansb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    