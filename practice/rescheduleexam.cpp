#include <bits/stdc++.h>
#define int long long
using namespace std;

bool valid(vector<int>& vec, int dist) {
  int last = 0;
  for (int i : vec) {
    if (i - last - 1 < dist) return false;
    last = i;
  }
  return true;
}

void print(vector<int>& a) {
  for (int i : a) cout << i << " ";
  cout << endl;
}

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto& i : a) cin >> i;

  int l = 0, r = d;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    int last = 0;
    bool works = true;
    for (int i = 0; i < n; i++) {
      if (a[i] - last - 1 < mid) {
        works = false;
        // either change the position of this one or the last one
        vector<int> check = {i};
        if (i > 0) check.push_back(i - 1);
        vector<int> test;
        for (int j : check) {
          if (a[0] != 1) {
            test.clear(); 
            test.push_back(1);
            for (int k = 0; k < n; k++) if (k != j) test.push_back(a[k]);
            if (valid(test, mid)) {
              works = true;
              break;
            }
          }
          if (a[n - 1] != d) {
            test.clear();
            for (int k = 0; k < n; k++) if (k != j) test.push_back(a[k]);
            test.push_back(d);
            if (valid(test, mid)) {
              
              works = true;
              break;
            }
          }
          
          test.clear();
          int before = 0;

          bool added = false;
          for (int k = 0; k < n; k++) {
            if (k == j) continue;
            else if (added) {
              test.push_back(a[k]);
              continue;
            }
            int diff = a[k] - before - 1;
            if ((diff - 1) / 2 >= mid) {
              added = true;
              test.push_back(before + (diff - 1) / 2 + 1);
            }
            test.push_back(a[k]);
            before = a[k];
          }

          if (added && valid(test, mid)) {
            works = true;
            break;
          }
        }
        break;
      }
      last = a[i];
    }
    

    if (works) l = mid + 1;
    else r = mid - 1;
  }

  cout << l - 1 << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
