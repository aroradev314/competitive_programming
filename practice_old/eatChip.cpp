#include <iostream>
#include <vector>
using namespace std;

bool get_away(int h, int w, int xa, int ya, int xb, int yb) {
	
	
	int meet = xa + (xb - xa) / 2 + 1;
	
	// cout << xa << " " << ya << " "  << xb << " " << yb << endl;
	
	// choose to go left
	bool get_away_left = max(1, yb - (xb - meet)) < max(1, ya - (meet - xa));
	bool get_away_right = min(w, yb + (xb - meet)) > min(w, ya + (meet - xa));
	
	return (get_away_left || get_away_right);
}



void test_case() {
	int h, w, xa, ya, xb, yb;
	cin >> h >> w >> xa >> ya >> xb >> yb;
	
	if (xa >= xb) {
		cout << "Draw\n";
		return;
	}
	
	if ((xb - xa) % 2 == 1) {		
		if (get_away(h, w, xa, ya, xb, yb)) {
			cout << "Draw\n";
		}
		else {
			cout << "Alice\n";
		}
	}
	else {
		xa++;
		
		int left = ya - 1;
		int straight = ya;
		int right = ya + 1;
		
		xb = h - xb + 1;
		yb = w - yb + 1;
		bool free = get_away(h, w, xb, yb, (h - xa + 1), (w - left + 1)) || get_away(h, w, xb, yb, (h - xa + 1), (w - straight + 1)) || get_away(h, w, xb, yb, (h - xa + 1), (w - right + 1));
		
		if (free) {
			cout << "Draw\n";
		}
		else {
			cout << "Bob\n";
		}
		
	}
}
	
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}
