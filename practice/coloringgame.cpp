#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> visited(n + 1, -1);
  bool bipartite = true;

  visited[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (visited[v] == -1) {
        visited[v] = 1 - visited[u];
        q.push(v);
      } else if (visited[v] == visited[u]) {
        bipartite = false;
        break;
      }
    }
  }

  if (bipartite) {
    cout << "Bob\n";

    vector<int> first, second;
    for (int i = 1; i <= n; i++) {
      if (visited[i] == 0)
        first.push_back(i);
      else
        second.push_back(i);
    }

    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if (a > b)
        swap(a, b);

      if (a == 1 && first.size()) {
        cout << first.back() << " 1\n";
        first.pop_back();
      } else if ((a == 2 || b == 2) && second.size()) {
        cout << second.back() << " 2\n";
        second.pop_back();
      } else {
        if (first.size() == 0) {
          cout << second.back() << " " << b << "\n";
          second.pop_back();
        } else {
          int cur = (a == 2 ? b : a);
          cout << first.back() << " " << cur << "\n";
          first.pop_back();
        }
      }
    }
  } else {
    cout << "Alice\n";
    for (int i = 0; i < n; i++) {
      cout << "1 2\n";
      int x, c;
      cin >> x >> c;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
