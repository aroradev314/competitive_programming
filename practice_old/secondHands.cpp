#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	freopen("a.out", "w", stdout);
	for (int i = 0; i < t; i++) {
		cout << "Case #" << (i + 1) << ": ";
		int n, k;
		cin >> n >> k;
		vector<int> styles(n);
		for (int j = 0; j < n; j++) {
			cin >> styles[j];
		}
		sort(styles.begin(), styles.end());
		if (k * 2 < n) {
			cout << "NO" << endl;
			continue;
		}
		
		string works = "YES";
		for (int j = 1; j < n - 1; j++) {
			if (styles[j - 1] == styles[j] && styles[j] == styles[j + 1]) {
				works = "NO";
				break;
			}
		}
		cout << works << endl;
	}
}

		
