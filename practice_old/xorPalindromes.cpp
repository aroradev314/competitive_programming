#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		
		bool odd = n % 2 == 1;
		
		int m = 0, d = 0;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == s[n - 1 - i]) {
				m += 2;
			}
			else {
				d++;
			}
		}
		
		for (int i = 0; i <= n; i++) {
			if (i >= d) {
				int left = i - d;
				if (left % 2 == 1 && odd) left--;
				if (left % 2 == 0 && left <= m) {
					cout << '1';
				}
				else {
					cout << '0';
				}
			}
			else {
				cout << '0';
			}
		}
		cout << endl;
	}
}

			
		
		
