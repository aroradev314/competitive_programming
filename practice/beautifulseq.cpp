#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> solve(int start, int a, int b, int c, int d) {
	vector<int> cur = {start};

	while (a | b | c | d) {
		// if (start == 0) cout << cur.back() << " " << a << " " << b << " " << c << " " << d << endl;
		if (cur.back() == 0) {
			if (b) {
				cur.push_back(1);
				b--;
			}
			else return {-1};
		}
		else if (cur.back() == 1) {
			if (a) {
				cur.push_back(0);
				a--;
			}
			else if (c) {
				cur.push_back(2);
				c--;
			}
			else return {-1};
		}
		else if (cur.back() == 2) {
			if (d) {
				cur.push_back(3);
				d--;
			}
			else if (b) {
				cur.push_back(1);
				b--;
			}
			else return {-1};
		}
		else {
			if (c) {
				cur.push_back(2);
				c--;
			}
			else return {-1};
		}
	}
	return cur;
}

void output(vector<int> v) {
	cout << "YES\n";
	for (int i : v) cout << i << " ";
	cout << "\n";
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	vector<int> ans = solve(0, a - 1, b, c, d);
	if (ans[0] != -1) {
		output(ans);
		return;
	}
	ans = solve(1, a, b - 1, c, d);
	if (ans[0] != -1) {
		output(ans);
		return;
	}
	ans = solve(2, a, b, c - 1, d);
	if (ans[0] != -1) {
		output(ans);
		return;
	}
	ans = solve(3, a, b, c, d - 1);
	if (ans[0] != -1) {
		output(ans);
		return;
	}

	cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    