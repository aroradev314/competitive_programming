// Source: https://usaco.guide/general/io

#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> shots(k + 1, vector<int>(n + 1));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> shots[i][j];
		}
	}

	if (k == 1 || n <= 2) {
		cout << "YES\n";
		return;
	}

	vector<int> order;
	for (int i = 2; i <= n; i++) order.push_back(shots[1][i]);

	int pos = -1;
	for (int i = 2; i <= n; i++) {
		if (shots[2][i] == shots[1][1]) {
			pos = i;
			break;
		}
	}

	if (pos == n && shots[1][pos] == shots[2][1]) {
		if (k >= 3) {
			order.pop_back();
			order.push_back(shots[3][n - 1]);
			order.push_back(shots[3][n]);
		}
		else {
			order.push_back(shots[1][1]);
		}
	}
	else if (pos == 2 && shots[1][pos] == shots[2][1]) {
		if (k >= 3) {
			order.erase(order.begin());
			order.insert(order.begin(), shots[3][3]);
			order.insert(order.begin(), shots[3][2]);
		}
		else {
			order.insert(order.begin(), shots[1][1]);
		}
	}
	else {
		int before = shots[2][pos - 1];
		for (int i = 2; i <= n; i++) {
			if (shots[1][i] == before) order.insert(order.begin() + i - 1, shots[1][1]);
		}
	}

	order.insert(order.begin(), 0);
	for (int i = 1; i <= k; i++) {
		int cur = 1;
		for (int j = 2; j <= n; i++) {
			if (cur < order.size()) cout << i << " " << shots.size() << endl;
			if (cur > n || order[cur] != shots[i][j]) {
				cout << "NO\n";
				cout << i << " " << j << "\n";
				return;
			}
		}
	}

	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) test_case();
}
