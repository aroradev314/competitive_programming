#include <vector>
#include <iostream>
#include <set>
using namespace std;

int ord(char c) {
	if (c <= 'Z') {
		return c - 'A';
	}
	else {
		return (('Z' - 'A') + (c - 'a') + 1);
	}
}

void test_case() {
	string a, b;
	cin >> a >> b;
	int n = a.length();
	vector<int> adj(52, -1);
	for (int i = 0; i < n; i++) {
		if (adj[ord(a[i])] != -1 && adj[ord(a[i])] != ord(b[i])) {
			cout << -1 << "\n";
			return;
		}
		adj[ord(a[i])] = ord(b[i]);
	}
	vector<int> in(52);
	for (int i = 0; i < 52; i++) {
		if (adj[i] != -1) {
			in[adj[i]]++;
		}
	}
	int ans = 0;
	bool found = false;
	vector<int> start;
	for (int i = 0; i < 52; i++) {
		if (!in[i]) {
			found = true;
			if (adj[i] != -1) {
				start.push_back(i);
			}
		}
		if (adj[i] != -1 && adj[i] != i) {
			ans++;
		}
		if (adj[i] == i) adj[i] = -1;
	}
	
	vector<bool> visited(52, false);
	for (int i : start) {
		int cur = i;
		while (cur != -1) {
			if (visited[cur]) break;
			visited[cur] = true;
			cur = adj[cur];
		}
	}
	
	for (int i = 0; i < 52; i++) {
		if (visited[i] || adj[i] == -1) continue;
		if (!found) {
			cout << -1 << "\n";
			return;
		}
		visited[i] = true;
		int cur = adj[i];
		while (cur != i) {
			visited[cur] = true;
			cur = adj[cur];
		}
		ans++;
	}
	cout << ans << endl;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

