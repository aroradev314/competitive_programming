#include <vector>
#include <iostream>
using namespace std;

const int MAX_N = 5e6 + 10;

vector<int> turns(MAX_N);

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int minTime = 2e9;
	bool john = true;
	for (int i = 0; i < n; i++) {
		if (turns[a[i]] / 2 < minTime) {
			minTime = turns[a[i]] / 2;
			john = a[i] % 4;
		}
	}
	
	if (john) {
		cout << "Farmer John\n";
	}
	else {
		cout << "Farmer Nhoj\n";
	}
}

int main() {
	vector<bool> prime(MAX_N, true);
	prime[1] = true;
	
	for (int i = 2; i < MAX_N; i++) {
		if (prime[i]) {
			for (int j = i + i; j < MAX_N; j += i) {
				prime[j] = false;
			}
		}
	}
	vector<int> maxPrime = {0, 0, 0, 0};
	for (int i = 1; i <= MAX_N; i++) {
		if (prime[i]) {
			maxPrime[i % 4] = i;
		}
		if (i % 4 == 0) {
			turns[i] = i / 2;
		}
		else {
			turns[i] = (i - maxPrime[i % 4]) / 2 + 1;
		}
	}
	
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

