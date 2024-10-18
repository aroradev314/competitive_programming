// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, n;
	cin >> c >> n;
	vector<int> cows(n);

	queue<int> q;
	vector<int> dist(1 << c, INT_MAX);
	vector<bool> visited(1 << c);
	for (int i = 0; i < n; i++) {
		string cur;
		cin >> cur;
		for (int j = 0; j < c; j++) {
			if (cur[j] == 'H') cows[i] |= (1 << j);
		}
		q.push(cows[i]);
		dist[cows[i]] = 0;
		visited[cows[i]] = true;
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < c; i++) {
			int flipped = cur ^ (1 << i);
			dist[flipped] = min(dist[flipped], dist[cur] + 1);
			if (visited[flipped]) continue;
			visited[flipped] = true;
			q.push(flipped);
		}
	}

	int all_on = (1 << c) - 1;
	for (int i = 0; i < n; i++) {
		int flipped = cows[i] ^ all_on;
		int ans = c - dist[flipped];
		cout << ans << "\n";
	}
}
