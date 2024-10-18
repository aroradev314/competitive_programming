#include <vector>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

vector<ll> fib(55);

void test_case() {
	int n;
	cin >> n;
	
	priority_queue<pair<ll, int>> nums;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		nums.push({a, i});
		sum += a;
	}
	
	if (n == 1) {
		cout << ((sum == 1) ? "YES\n" : "NO\n");
		return;
	}
	
	ll cur = 0;
	int last = 0;
	while (cur < sum) {
		cur += fib[last];
		last++;
	}
	if (cur != sum) {
		cout << "NO\n";
		return;
	}
	
	int last_id = -1;
	for (int i = last - 1; i >= 0; i--) {
		auto mx = nums.top();
		nums.pop();
		if (mx.second == last_id) {
			auto other = nums.top();
			nums.pop();
			nums.push(mx);
			mx = other;
		}
		
		if (mx.first < fib[i]) {
			cout << "NO\n";
			return;
		}
		else {
			mx.first -= fib[i];
			nums.push(mx);
			last_id = mx.second;
		}
	}
	cout << "YES\n";	
}

int main() {
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 55; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

