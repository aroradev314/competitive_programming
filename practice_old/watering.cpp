#include <vector>
#include <iostream>
using namespace std;

void test_case() {
	int n, k, d;
	cin >> n >> k >> d;
	
	vector<int> start(n), ops(k);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> start[i];
		if (start[i] == i + 1) cur++;
	}
	for (int i = 0; i < k; i++) cin >> ops[i];
	
	int max_days = min(d, (n * 2) + 10);
	
	int best = 0;
	for (int i = 0; i < max_days; i++) {
		best = max(best, cur + (d - i - 1) / 2);
		
		cur = 0;
		for (int j = 0; j < ops[i % k]; j++) {
			start[j]++;
		}
		for (int j = 0; j < n; j++) {
			if (start[j] == j + 1) cur++;
		}
	}
	cout << best << "\n";
}
	
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

