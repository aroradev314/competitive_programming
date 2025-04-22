#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

struct Cell {
	int x, y;

	Cell(int a, int b) : x(a), y(b) {}

	bool operator<(const Cell& other) const {
		int d1 = x + y + ((x % 3 == 2 && y % 3 == 2) ? 2 : 0);
		int d2 = other.x + other.y + ((other.x % 3 == 2 && other.y % 3 == 2) ? 2 : 0);
		if (d1 != d2) return (d1 < d2);
		if (x != other.x) return (x < other.x);
		return (y < other.y);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	set<Cell> cells;
	int cx = 0, cy = 0;

	int x, y;
	// try to open a new unopened one. if the current best cell one isnt optimal, then that one definitely is. 
	for (int i : a) {
		bool found = false;
		if (i == 1 && sz(cells)) {
			found = true;
			x = (*cells.begin()).x, y = (*cells.begin()).y;
			if (Cell(3 * cx + 1, 3 * cy + 1) < (*cells.begin())) {
				found = false;
			}
			else cells.erase(cells.begin());
		}
		if (!found) {
			x = 3 * cx + 1, y = 3 * cy + 1;
			cells.insert(Cell(3 * cx + 2, 3 * cy + 1));
			cells.insert(Cell(3 * cx + 1, 3 * cy + 2));
			cells.insert(Cell(3 * cx + 2, 3 * cy + 2));
			if (cy == 0) {
				cy = cx + 1;
				cx = 0;
			}
			else {
				cx++;
				cy--;
			}
		}
		cout << x << " " << y << "\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    