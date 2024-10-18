#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	string ans = "";
	char dir = 'R';
	int pos = 0;
	
	while (sum > 0) {
		if (dir == 'R') {
			if (pos == n || a[pos + 1] == 0) {
				dir = 'L'; 
			}
		}
		else {
			if (pos == 0 || (a[pos + 1] > 0 && a[pos] == 1)) {
				dir = 'R';
			}
		}
		ans += dir;
		if (dir == 'R') {
			pos++;
			a[pos]--;
		}
		else {
			a[pos]--;
			pos--;
		}
		
		sum--;
	}
	cout << ans;
}

			
		
	
	
