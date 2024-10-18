#include <vector>
#include <iostream>
using namespace std;

struct BIT {
	vector<long long> p;
	int n;
	BIT(int len) : p(len + 1), n(len) {}
	
	void update(int j, long long val) {
		for (int i = j; i <= n; i += (i & -i)) {
			p[i] += val;
		}
	}
	
	long long query(int j) {
		long long sum = 0;
		for (int i = j; i >= 1; i -= (i & -i)) {
			sum += p[i];
		}
		return sum;
	}
};
	
int main() {
	int n;
	cin >> n;
	
	BIT bit(n);
	
	vector<int> last(n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		
		if (last[k] != 0) {
			bit.update(last[k], -1);
		}
		
		ans += bit.query(i) - bit.query(last[k]);
		bit.update(i, 1);
		last[k] = i;
	}
	cout << ans;
}

		
		
		
	
