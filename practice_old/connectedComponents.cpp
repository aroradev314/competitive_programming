#include <set>
#include <iostream>
using namespace std;

vector<unordered_set<int>> adj;
set<int> unvis;
vector<int> size;
int cur;

void dfs(int x) {
	size[cur]++;
	auto it = unvis.begin();
	while (it != unvis.end()) {
		if (adj[x].count(*it) {
			it++;
		}
		else {
			int last = *it;

int main() {
	int n, m;
	cin >> n >> m;
	adj = vector<unordered_set<int>>(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	for (int i = 0; i < n; i++) {
		unvis.insert(i);
	}
	cur = 0;
	size = vector<int>(n);
	for (int i = 0; i < n; i++) {
		auto it = unvis.find(i);
		if (it != unvis.end()) {
			unvis.erase(it);
			dfs(i);
			cur++;
		}
	}
	cout << cur << endl;
	sort(size.begin(), size.begin() + cur);
	for (int i = 0; i < cur; i++) {
		cout << size[i];
	}
	cout << endl;
}
		
		
			
	
	
