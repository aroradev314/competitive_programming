#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<bitset<>> r;
	for (int i = 1; i <= n - 1; i++) {
		string s;
		cin >> s;
		s = string(i + 1, '0') + s;
		routes[i] = bitset<n + 1>(s);
	}
	routes[n] = bitset(string(n + 1, '0'));
	
	int total = 0;
	for (int i = n - 1; i >= 1; i--) {
		bitset cur(string(n + 1, '0'));
		for (int j = i + 1; j <= n; j++) {
			if (routes[i][j] != cur[j]) {
				total++;
				
				string other = routes[j];
				
				cur = cur ^ other;
			}
		}
	}
	
	cout << total;
}
				 
