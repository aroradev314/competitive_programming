// USACO 2020 Silver P2

#include <vector>
#include <iostream>
using namespace std;

struct cow {
	int x, y;
	char dir;
};

int timeToIntersect(cow mover, cow stopper) {
	if (mover.dir == stopper.dir) {
		return -1;
	}
	if (stopper.dir == 'E') {
		if (mover.x - stopper.x < stopper.y - mover.y && mover.x - stopper.x >= 0 && stopper.y - mover.y >= 0) {
			return stopper.y - mover.y;
		}
		return -1;
	}
	else {
		if (mover.y - stopper.y < stopper.x - mover.x && mover.y - stopper.y >= 0 && stopper.x - mover.x >= 0) {
			return stopper.x - mover.x;
		}
		return -1;
	}
}

		

int main() {
	int n;
	cin >> n;
	
	vector<cow> cows(n);
	
	for (int i = 0; i < n; i++) {
		cow current;
		cin >> current.dir >> current.x >> current.y;
	}
	
	vector<int> blame(n);
	
	for (int i = 0; i < n; i++) {
		int minDistance = INT_MAX;
		int cowBlame = -1;
		for (int j = 0; j < n; j++) {
			int intersect = timeToIntersect(cows[i], cows[j]);
			if (intersect != -1 && intersect < minDistance) {
				minDistance = intersect;
				cowBlame = j;
			}
		}
		if (cowBlame != -1) {
			blame[cowBlame]++;
		}
	}
	for (int i : blame) {
		cout << i << endl;
	}
}

		
	
	
	
