#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, c;
	cin >> t >> c;
	
	set<int> targets;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		targets.insert(a);
	}
	string command;
	cin >> command;
	
	int curPos = 0;
	for (int i = 0; i < c; i++) {
		if (command[i] == 'L') {
			curPos--;
		}
		else if (command[i] == 'R') {
			curPos++;
		}
	}
	
	vector<int> twoRight(c + 1), oneRight(c + 1), twoLeft(c + 1), oneLeft(c + 1);
	set<int> s1, s2, s3, s4;
	
	int pos = curPos;
	for (int i = c - 1; i >= 0; i--) {
		twoRight[i] = twoRight[i + 1];
		oneRight[i] = oneRight[i + 1];
		twoLeft[i] = twoLeft[i + 1];
		oneLeft[i] = oneLeft[i + 1];
		
		if (!(command[i] == 'F')) {
			if (command[i] == 'R') {
				pos--;
			}
			else {
				pos++;
			}
			continue;
		}
		
		if (!s1.count(pos + 2) && targets.count(pos + 2)) {
			twoRight[i]++;
			s1.insert(pos + 2);
		}
		if (!s2.count(pos + 1) && targets.count(pos + 1)) {
			oneRight[i]++;
			s2.insert(pos + 1);
		}
		if (!s3.count(pos - 2) && targets.count(pos - 2)) {
			twoLeft[i]++;
			s3.insert(pos - 2);
		}
		if (!s4.count(pos - 1) && targets.count(pos - 1)) {
			oneLeft[i]++;
			s4.insert(pos - 1);
		}
	}
	pos = 0;
	set<int> current;
	int ans = 0;
	for (int i = 0; i < c; i++) {
		int s = current.size();
		if (command[i] == 'L') {
			ans = max(ans, s + twoRight[i + 1]);
			ans = max(ans, s + oneRight[i + 1] + int(targets.count(pos) && !current.count(pos)));
			pos--;
		}
		else if (command[i] == 'R') {
			ans = max(ans, s + twoLeft[i + 1]);
			ans = max(ans, s + oneLeft[i + 1] + int(targets.count(pos) && !current.count(pos)));
			pos++;
		}
		else {
			ans = max(ans, s + oneRight[i + 1]);
			ans = max(ans, s + oneLeft[i + 1]);
			if (targets.count(pos)) {
				current.insert(pos);
			}
		}
	}
	ans = max(ans, (int) current.size());
	
	cout << ans;
}
