#include <stack>
#include <iostream>
#include <limits.h>
#include <vector>
using ll = long long;
using namespace std;

int n;
vector<int> a, v;
vector<vector<int>> reversed;
vector<bool> visited;

void dfs(int node) {
	visited[node] = true;
	for (int i : reversed[node]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int min_in_cycle(int cur) {
	int x = a[cur];
	int y = a[x];
	while (x != y) {
		x = a[x];
		y = a[a[y]];
	}
	int min_element = v[x];
	x = a[x];
	while (x != y) {
		min_element = min(min_element, v[x]);
		x = a[x];
	}
	dfs(cur);
	return min_element;
}


int main() {
	cin >> n;
	a = vector<int>(n);
	v = vector<int>(n);
	visited = vector<bool>(n);
	reversed = vector<vector<int>>(n);
	ll total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> v[i];
		a[i]--;
		reversed[a[i]].push_back(i);
		total += v[i];
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			total -= min_in_cycle(i);
		}
	}
	cout << total << endl;
		
}
	
	
	
	
	
	
