#include <bits/stdc++.h>
typedef long long ll;
#define int long long
using namespace std;

ll arithmetic(ll a, ll b, ll terms) {
  ll tot = terms * (a + b) / 2;
  return tot;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  int l = 0, r = 1e9;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    int tot = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= mid) tot += 1 + (a[i] - mid) / b[i];
    }

    if (tot >= k) l = mid + 1;
    else r = mid - 1;
  }

  int x = l - 1;
  // subtract until u have x + 1 on each

  ll ans = 0;
  ll totterms = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= x + 1) {
      ll terms = 1 + (a[i] - (x + 1)) / b[i];
      ll last = a[i] - (terms - 1) * b[i];
      ans += arithmetic(a[i], last, terms);
      a[i] -= terms * b[i];
      a[i] = max(a[i], 0LL);
      totterms += terms;
    }
  }
  
  k -= totterms;


  priority_queue<pair<ll, ll>> pq;
  for (int i = 0; i < n; i++) pq.push({a[i], i});

  while (k--) {
    auto top = pq.top();
    pq.pop();
    if (top.first <= 0) break;
    ans += top.first;
    pq.push({top.first - b[top.second], top.second});
  }
  
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
