#include <iostream>
#include <vector>
using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	
	int left = 0, right = 1e9;
	while (left <= right) {
		int k = left + (right - left) / 2;
		
		pair<int, int> cur = {0, 0};
		bool works = true;
		for (int i = 0; i < n; i++) {
			cur.first -= k;
			cur.second += k;
			
			cur.first = max(cur.first, l[i]);
			cur.second = min(cur.second, r[i]);
			if (cur.first > cur.second) {
				works = false;
				break;
			}
		}
		
		if (works) {
			right = k - 1;
		}
		else {
			left = k + 1;
		}
	}
	cout << right + 1 << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

