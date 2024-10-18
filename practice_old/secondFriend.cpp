#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	freopen("a.out", "w", stdout);
	
	for (int i = 0; i < t; i++) {
		int r, c;
		cin >> r >> c;
		
		string trash;
		bool foundTree = false;
		for (int j = 0; j < r; j++) {
			cin >> trash;
			for (int k = 0; k < c; k++) {
				if (trash[k] == '^') {
					foundTree = true;
				}
			}
		}
		
		cout << "Case #" << (i + 1) << ": ";
		if ((r == 1 || c == 1) && foundTree) {
			if (foundTree) {
				cout << "Impossible" << endl;
			}
		}
		else {
			cout << "Possible" << endl;
			char x = foundTree ? '^' : '.';
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cout << x;
				}
				cout << endl;
			}
		}
	}
}

		
