#include <vector>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> even, odd;
		
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a % 2 == 0) {
				even.push_back(a);
			}
			else {
				odd.push_back(a);
			}
		}
		
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		
		int total = 0;
		
		for (int i = 1; i < even.size(); i++) {
			if (even[i] != even[i - 1] + 2) {
				total++;
			}
		}
		for (int i = 1; i < odd.size(); i++) {
			if (odd[i] != odd[i - 1] + 2) {
				total++;
			}
		}
		
		if (even.size() > 0) {
			total++;
		}
		if (odd.size() > 0) {
			total++;
		}
		
		cout << total << endl;
	}
}

		
		
