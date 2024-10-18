// USACO Silver 2015 February 
// P3

#include <vector>
#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int MOD = 1000000007;

int main() {
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<bool> used(n);
	ll result = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto node = pq.top();
		pq.pop();
		int nodeInd = node.second;
		if (used[nodeInd]) continue;
		
		result += node.first;
		used[nodeInd] = true;
		
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				pq.push({a[nodeInd] ^ a[i], i});
			}
		}
	}

	cout << result << endl;
	
	
	
}
	
	
	

