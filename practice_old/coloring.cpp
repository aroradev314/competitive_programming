// Source: https://usaco.guide/general/io

#include <vector>
#cin
#define int long long
using namespace std;

void test_case() {
	int n, m, k;
	cin >> n >> m >> k;
	int times = 0;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (num > (n + k - 1) / k) {
			times = INT_MAX;
		}
		if (num == (n + k - 1) / k) times++;
	}
	
	cout << (times <= (n - 1) % k + 1 ? "YES\n" : "NO\n");
}

int64_t main() {
	int t;
	cin >> t;
	while (t--) test_case();
}
