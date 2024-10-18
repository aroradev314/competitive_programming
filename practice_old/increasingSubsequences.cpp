#include <vector>
#include <iostream>
using namespace std;

void create(long long num, vector<bool>& cur) {
	if (num == 2) {
		cur.push_back(true);
		return;
	}
	if (num % 2 == 0) {
		create(num / 2, cur);
		cur.push_back(true);
	}
	else {
		create(num - 1, cur);
		cur.push_back(false);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long num;
		cin >> num; 
		vector<bool> cur;
		create(num, cur);
		int mx = 1, mn = 0;
		cout << cur.size() << "\n";
		for (bool i : cur) {
			if (i) {
				cout << mx << " ";
				mx++;
			}
			else {
				cout << mn << " ";
				mn--;
			}
		}
		cout << "\n";
	}
}

