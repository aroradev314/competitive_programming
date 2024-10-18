#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
  int n, C;
  cin >> n >> C;

  vector<int> bst(C + 1);
  for (int i = 0; i < n; i++) {
    int c, d, h;
    cin >> c >> d >> h;
    bst[c] = max(bst[c], d * h);
  }

  for (int c = 1; c <= C; c++) {
    for (int xc = c; xc <= C; xc += c) bst[xc] = max(bst[xc], (xc / c) * bst[c]);
  }

  for (int c = 1; c <= C; c++) bst[c] = max(bst[c], bst[c - 1]);

  int m;
  cin >> m;
  while (m--) {
    int D, H;
    cin >> D >> H;

    int ans = upper_bound(bst.begin(), bst.end(), D * H) - bst.begin();
    if (ans > C) cout << "-1 ";
    else cout << ans << " ";
  }
}
