#include <iostream>
#include <algorithm>
using namespace std;
void test_case() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if (a == 0) {
		cout << 1 << endl;
		return;
	}
	cout << a + min(b, c) * 2 + min(a + 1, abs(b - c) + d) << endl;
}
	
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
