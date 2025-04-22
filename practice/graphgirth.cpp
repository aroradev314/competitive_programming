#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2550;
const int INF = 2e9;
vector<int> adj[MAX_N];
bool good[MAX_N];
int dist[MAX_N];
int last[MAX_N];
int num[MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			good[j] = false;
			dist[j] = INF;
			num[j] = 0;
		}
		for (int j : adj[i]) good[j] = true;
		dist[i] = 0;

		queue<int> q;
		q.push(i);
		vector<int> vis;
		while (!q.empty()) {
			int u = q.front();
			vis.push_back(u);
			q.pop();

			for (int v : adj[u]) {
				if (dist[v] == INF) {
					dist[v] = dist[u] + 1;
					last[v] = u;
					num[v] = 1;
					q.push(v);
				}
				else if (dist[v] == dist[u] + 1) num[v]++;
			}
		}

		for (int j : vis) 
			for (int k : adj[j]) 
				if (j != i && k != i && abs(dist[j] - dist[k]) <= 1 && !(last[j] == k || last[k] == j) && (last[j] != last[k] || num[j] >= 2 || num[k] >= 2 || last[j] == i)) 
					ans = min(ans, dist[j] + dist[k] + 1);
	}
	cout << (ans == INF ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    