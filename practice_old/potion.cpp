#include <vector>
#include <set>
#include <iostream>
using namespace std;

multiset<int> leaves;
vector<vector<int>> adj;
vector<int> anc;

void find_leaves(int cur, int parent) {
	if (cur != 1 && adj[cur].size() == 1) leaves.insert(cur);
	
	anc[cur] = parent;
	for (int n : adj[cur]) {
		if (n != parent) find_leaves(n, cur);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	
	adj.resize(n + 1);
	anc.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	find_leaves(1, -1);
	
	multiset<int> check;
	for (int i = 0; i < (int) leaves.size(); i++) {
		check.insert(p[i]);
	}
	// for (int i : check) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// for (int i : leaves) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	
	
	int ans = 0;
	while (leaves.size() != 0) {
		multiset<int> new_leaves;
		for (int i : leaves) {
			if (check.count(i)) {
				check.erase(check.find(i));
				ans++;
			}
			else if (anc[i] != -1) new_leaves.insert(anc[i]);
		}
		leaves = new_leaves;
	}
	
	cout << ans;
}

			
	
	
	
	
	
	
	
	
