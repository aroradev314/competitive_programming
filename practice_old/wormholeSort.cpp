/*
 * USACO 2020 January Contest, Silver
 * Problem 3. Wormhole Sort
 * finish later
 
*/
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

struct wormhole {
	int a, b, w;
};

vector<int> nums;
vector<wormhole> wormholes;
vector<vector<int>> adj;
vector<bool> visitedPos, visitedVal, overallVisited;
int n, m;


void dfs(int node) {
	visitedPos[node] = true;
	overallVisited[node] = true;
	visitedVal[nums[node]] = true;
	for (int i : adj[node]) {
		if (!visitedPos[i]) {
			dfs(i);
		}
	}
	return;
}
	
	

bool works(int width) {
	adj = vector<vector<int>>(n + 1);	
	for (wormhole i : wormholes) {
		if (i.w >= width) {
			adj[i.a].push_back(i.b);
			adj[i.b].push_back(i.a);
		}
	}
	vector<bool> found(n + 1);
	overallVisited = vector<bool>(n + 1);
	for (int i = 1; i <= n; i++) {
		if (!overallVisited[i]) {
			visitedPos = vector<bool>(n + 1);
			visitedVal = vector<bool>(n + 1);
			dfs(i);
			for (int j = 1; j <= n; j++) {
				if (visitedPos[j] && visitedVal[j]) {
					found[j] = true;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!found[i] && nums[i] != i) {
			return false;
		}
	}
	return true;
}

int binarySearch() {
	long long left = 0;
	long long right = INT_MAX;
	int ans = -1;
	while (left <= right) {
		long long middle = left + (right - left) / 2;
		if (works(middle)) {
			left = middle + 1;
			ans = middle;
		}
		else {
			right = middle - 1;
		}
	}
	if (ans == INT_MAX) {
		return -1;
	}
	return ans;
}	
	
int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	cin >> n >> m;
	nums = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	wormholes = vector<wormhole>(m + 1);
	for (int i = 1; i <= m; i++) {
		wormhole current;
		cin >> current.a >> current.b >> current.w;
		wormholes[i] = current;
	}
	overallVisited = vector<bool>(n + 1);
	cout << binarySearch() << endl;	
}
	
