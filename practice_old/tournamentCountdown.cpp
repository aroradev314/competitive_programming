#include <vector>
#include <iostream>
using namespace std;

int query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int ans;
	cin >> ans;
	return ans;
}

int ask(int a, int b, int c, int d) {
	int comp = query(a, c);
	
	if (comp == 0) {
		return query(b, d) == 1 ? b : d;
	}
	else if (comp == 1) {
		return query(a, d) == 1 ? a : d;
	}
	else {
		return query(c, b) == 1 ? c : b;
	}
}	

void test_case() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 1; i <= (1 << n); i++) {
		a.push_back(i);
	}
	
	vector<int> b;
	while (a.size() > 2) {
		for (int i = 0; i < a.size(); i += 4) {
			int pos = ask(a[i], a[i + 1], a[i + 2], a[i + 3]);
			b.push_back(pos);
		}
		a = b;
		b.clear();
	}
	int ans = query(a[0], a[1]) == 1 ? a[0] : a[1];
	cout << "! " << ans << endl;
}

int main() {
	int t;
	cin >> t;
	 
	while (t--) {
		test_case();
	}
}

