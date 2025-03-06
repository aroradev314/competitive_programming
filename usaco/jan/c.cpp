#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
using namespace std;

int n;

void ck_min(vector<vector<int>>& cur, vector<vector<int>> other) {
	if (cur[0][0] == -1) {
		cur = other;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cur[i][j] < other[i][j]) return;
			else if (other[i][j] < cur[i][j]) {
				cur = other;
				return;
			}
		}
	}
}

void solve() {
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<int> cnt(2 * n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}

	vector<vector<int>> opp(n + 1);
	for (int i = 2; i <= 2 * n; i++) opp[cnt[i]].push_back(i);


	if (n == 1) {
		cout << a[0][0] << "\n";
		return;
	}

	vector<set<int>> index(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) index[i].insert(a[i][j]);

	vector<vector<int>> ans(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		int num = -1;
		for (int j = 0; j < n; j++) if (cnt[a[i][j]] == 1) {
			num = a[i][j];
			break;
		}

		if (num == -1) continue;

		vector<int> cnt_copy = cnt;
		vector<int> ord = {num};
		vector<bool> seen(n);
		seen[i] = true;

		int cur = -1;
		for (int j = 0; j < n; j++) {
			cnt_copy[a[i][j]]--;
			if (cnt_copy[a[i][j]] == 1) cur = a[i][j];
		}
		assert(cur != -1);

		for (int j = 1; j < n - 1; j++) {
			ord.push_back(cur);
			for (int k = 0; k < n; k++) {
				if (seen[k]) continue;
				if (index[k].count(cur)) {
					seen[k] = true;
					for (int l = 0; l < n; l++) {
						cnt_copy[a[k][l]]--;
						if (cnt_copy[a[k][l]] == 1) cur = a[k][l];
					}
					break;
				}
			}
		}
		for (int j = 2; j <= 2 * n + 1; j++) {
			if (cnt[j] == n) ord.push_back(j);
		}

		vector<int> fin_ord = ord;
		for (int j = sz(ord) - 2; j >= 0; j--) {
			int c = cnt[ord[j]];
			int which = 0;
			if (opp[c][which] == ord[j]) which++;
			fin_ord.push_back(opp[c][which]);
		}

		for (int rep = 0; rep < 2; rep++) {
			vector<int> which(2 * n + 1);
			for (int j = 0; j < sz(fin_ord); j++) which[fin_ord[j]] = 2 + j;

			vector<vector<int>> cand(n, vector<int>(n));
			bool works = true;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					cand[j][k] = which[a[j][k]];
					// if (cand[j][k] == 0) works = false;
				}
			}
			if (works) ck_min(ans, cand);
			reverse(fin_ord.begin(), fin_ord.end());
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
			if (j != n - 1) cout << " ";
		}
		if (i != n - 1) cout << "\n";
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    