#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long long> g(n), a(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i] += abs(g[i] - g[j]);
		}
	}
	
	long long minAloof = a[0];
	int minIndex = 0;
	
	for (int i = 1; i < n; i++) {
		if (a[i] < minAloof) {
			minAloof = a[i];
			minIndex = i;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == minAloof && i != minIndex) {
			minIndex = -1;
		}
	}
	cout << minIndex;
}
	
	
