#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> factors(1e5 + 1);
vector<bool> isPrime(1e5 + 1, true);

void factorize(int num) {
	fill(factors.begin(), factors.end(), 0);
	for (int i = 2; i <= 1e5; i++) {
		if (isPrime[i]) {
			while (num % i == 0) {
				num /= i;
				factors[i]++;
			}
		}
	}
}
	
void test_case() {
	int n;
	cin >> n;
	factorize(n);
	
	multiset<int> ans;
	int total = 0;
	for (int i = 2; i <= 1e5; i++) {
		for (int j = 0; j < factors[i]; j++) {
			ans.insert(i);
			total += i;
		}
	}
	if (total > 41) {
		cout << -1 << endl;
	}
	else {
		while (ans.size() >= 2) {
			int first = *(ans.begin());
			int second = *(next(ans.begin()));
			if (total - first - second + first * second <= 41) {
				total = total - first - second + first * second;
				ans.erase(ans.begin());
				ans.erase(next(ans.begin()));
				ans.insert(first * second);
			}
			else {
				break;
			}
		}
		for (int i = total; i < 41; i++) {
			ans.insert(1);
		}
		cout << (int) ans.size() << " ";
		for (int i : ans) {
			cout << i << " ";
		}
		cout << endl;
	}
}
	
int main() {
	// freopen("sum_41_chapter_1_input.txt", "r", stdin);
	// freopen("sum_41_validation_full_output.txt", "w", stdout);
	for (int i = 2; i <= 1e5; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 1e5; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		test_case();
	}
}
