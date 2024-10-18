// Source: https://usaco.guide/general/io

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	cout << "? 1 " << n << endl;
	int second_max; cin >> second_max;
	
	bool first_half;
	if (n == 2) {
		cout << "! " << 3 - second_max << endl;
		return 0;
	}
	else if (second_max == 1) first_half = false;
	else {
		cout << "? 1 " << second_max << endl;
		int other; cin >> other;
		first_half = (other == second_max);
	}
	
	int l, r;
	if (first_half) {
		l = 1, r = second_max - 1;

		while (l + 1 < r) {
			int mid = (l + r) / 2;
			cout << "? " << mid << " " << second_max << endl;
			if (second_max == 1) cout << "? ASD" << l << r << endl;
			int ans; cin >> ans;

			if (ans == second_max) l = mid;
			else r = mid;
		}
	}
	else {
		l = second_max + 1, r = n;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			cout << "? " << second_max << " " << mid << endl;
			if (mid == 1) cout << "? pld" << l << r << endl;
			int ans; cin >> ans;

			if (ans == second_max) r = mid;
			else l = mid;
		}
	}

	if (l == r) cout << "! " << l << endl;
	else {
		cout << "? " << l << " " << r << endl;
		int ans; cin >> ans;

		cout << "! " << (ans == l ? r : l) << endl;
	}
}
