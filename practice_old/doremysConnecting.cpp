#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

void test_case() {
	int n, c;
	cin >> n >> c;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int tot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] >= (i + 1) * (j + 1) * c) {
				tot++;
			}
		}
	}
	if (tot >= n - 1) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

