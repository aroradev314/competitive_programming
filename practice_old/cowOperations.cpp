#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> c(n + 1), o(n + 1), w(n + 1);
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + int(s[i - 1] == 'C');
		o[i] = o[i - 1] + int(s[i - 1] == 'O');
		w[i] = w[i - 1] + int(s[i - 1] == 'W');
	}
	
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		
		int cs = c[r] - c[l - 1];
		int os = o[r] - o[l - 1];
		int ws = w[r] - w[l - 1];
		
		if ((os % 2 == ws % 2) && (cs % 2 != os % 2)) {
			cout << 'Y';
		}
		else {
			cout << 'N';
		}
	}
}
