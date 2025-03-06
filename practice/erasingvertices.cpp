#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 110;
int s[MAX_N];
string adj[MAX_N];

ld ONE = 1.0;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> adj[i];

    ld ans = 0;
    for (int i = 0; i < n; i++) {
    	vector<bool> visited(n);
    	queue<int> q;
    	q.push(i);
    	visited[i] = true;
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		s[i]++;
    		for (int j = 0; j < n; j++) if (adj[j][u] == '1' && !visited[j]) {
    			q.push(j);
    			visited[j] = true;
    		}
    	}
    	ans += (ONE / s[i]);
    }

    cout << fixed << setprecision(20) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    