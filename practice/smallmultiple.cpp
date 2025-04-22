#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_K = 1e5 + 10;
const int INF = 2e9;
int dist[MAX_K];

void solve() {
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) dist[i] = INF;
	dist[1] = 1;
	
	deque<int> d;
	d.push_front(1);

	while (!d.empty()) {
		int c = d.front();
		d.pop_front();

		if (dist[c] < dist[(10 * c) % k]) {
			dist[(10 * c) % k] = dist[c];
			d.push_front((10 * c) % k);
		}
		if (dist[c] + 1 < dist[(c + 1) % k]) {
			dist[(c + 1) % k] = dist[c] + 1;
			d.push_back((c + 1) % k);
		}
	}

	cout << dist[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    