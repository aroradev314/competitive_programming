#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  s = " " + s;
  vector<vector<int>> pref(n + 1, vector<int>(26));
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    pref[i][s[i] - 'a']++;
  }

  vector<vector<int>> seen(26);
  for (int i = n; i >= 1; i--) seen[s[i] - 'a'].push_back(i);



}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
