#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> ans(n + 1);
	
	int dk = 1;
	
	for (int i = 2; i <= n; i++) {
		int first, second;
		cout << "? " << dk << " " << i << endl;
		cin >> first;
		cout << "? " << i << " " << dk << endl;
		cin >> second;
		
		if (first > second) {
			ans[dk] = first;
			dk = i;
		}
		else {
			ans[i] = second;
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) cout << n << " ";
		else cout << ans[i] << " ";
	}
}

