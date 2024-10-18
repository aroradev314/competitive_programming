#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

void erase(map<int, int>& cur, int pos) {
	if (!cur.count(pos)) return;
	cur[pos]--;
	if (cur[pos] == 0) cur.erase(pos);
}

int main() {
	int t, c;
	cin >> t >> c;
	
	set<int> targets;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		targets.insert(a);
	}
	string moves;
	cin >> moves;
	
	int pos = 0;
	map<int, int> one_right, one_left, two_right, two_left;
	for (int i = 0; i < c; i++) {
		if (moves[i] == 'R') pos++;
		else if (moves[i] == 'L') pos--;
		else {
			if (targets.count(pos + 2)) two_right[pos + 2]++;
			if (targets.count(pos + 1)) one_right[pos + 1]++;
			if (targets.count(pos - 1)) one_left[pos - 1]++;
			if (targets.count(pos - 2)) two_left[pos - 2]++;
		}
	}
	
	pos = 0;
	int ans = 0;
	set<int> shot;
	for (int i = 0; i < c; i++) {
		if (moves[i] == 'L') {
			// change it to an R
			ans = max(ans, (int) shot.size() + (int) two_right.size());
			// change it to an F
			ans = max(ans, (int) shot.size() + (int) one_right.size() + int(!shot.count(pos) && !one_right.count(pos) && targets.count(pos)));
			
			pos--;
		}
		else if (moves[i] == 'R') {
			// change it to an L
			ans = max(ans, (int) shot.size() + (int) two_left.size());
			// change it to an F
			ans = max(ans, (int) shot.size() + (int) one_left.size() + int(!shot.count(pos) && !one_left.count(pos) && targets.count(pos)));
			
			pos++;
		}
		else {
			erase(two_right, pos + 2);
			erase(one_right, pos + 1);
			erase(one_left, pos - 1);
			erase(two_left, pos - 2);
			
			// change F to L
			ans = max(ans, (int) shot.size() + (int) one_left.size());
			ans = max(ans, (int) shot.size() + (int) one_right.size());
			
			shot.insert(pos);
			two_right.erase(pos);
			one_right.erase(pos);
			one_left.erase(pos);
			two_left.erase(pos);
		}
	}
	ans = max(ans, (int) shot.size());
	cout << ans;
}

		
			
			
		
		
	
	
	
