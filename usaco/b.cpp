#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> trees(n);
	for (int i = 0; i < n; i++) cin >> trees[i];
	vector<int> l(k), r(k), t(k);
	for (int i = 0; i < k; i++) cin >> l[i] >> r[i] >> t[i];

	vector<int> indices(k);
	for (int i = 0; i < k; i++) indices[i] = i;
	sort(indices.begin(), indices.end(), [&] (int x, int y) {
		return l[x] < l[y];
	});

	sort(trees.begin(), trees.end());


	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int d = 0, cur = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (cur < k && l[indices[cur]] <= trees[i]) {
			int idx = indices[cur];
			auto elements = upper_bound(trees.begin(), trees.end(), r[idx]);
			elements--;
			int index = elements - trees.begin();
			// cout << i << " " << index << endl;
			pq.push({(index - i + 1) - t[idx] + d, idx});
			cur++;
		}
		while (!pq.empty()) {
			if (r[pq.top().second] < trees[i]) pq.pop();
			else break;
		}

		if (!pq.empty() && pq.top().first - d > 0) {
			d++;
			ans++;
		}
		else if (pq.empty()) {
			d++;
			ans++;
		}
	}	

	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}