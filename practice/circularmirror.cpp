#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int MAX_N = 3e5;
int fact[MAX_N + 10];

int mul(int a, int b) {
  return (a * b) % MOD;
}

int add(int a, int b) {
  a += b;
  while (a < 0) a += MOD;
  while (a >= MOD) a -= MOD;
  return a;
}

int binpow(int a, int b) {
  if (b == 0) return 1;
  int ans = binpow(a, b / 2);
  ans = mul(ans, ans);

  if (b % 2) ans = mul(ans, a);
  return ans;
}

int inv(int a) {
  return binpow(a, MOD - 2);
}

int choose(int a, int b) {
  if (a < b) return 0;

  int denom = inv(mul(fact[b], fact[a - b]));
  return mul(fact[a], denom);
}

int32_t main() {
  fact[0] = 1;
  for (int i = 1; i <= MAX_N; i++) fact[i] = mul(fact[i - 1], i);

  int n, m;
  cin >> n >> m;

  int len = 0;
  set<int> d;
  for (int i = 0; i < n; i++) {
    int num; cin >> num;
    if (i != n - 1) d.insert(len + num);
    else d.insert(0);
    len += num;
  }

  int opp = 0, diff = n;
  
  if (len % 2 == 0) {
    for (int i : d) {
      if (d.count((i + len / 2) % len)) {
        opp++;
        diff--;
      }
    }
  }

  int ans = 0;
  int pairs = opp / 2;


  // i pairs are the same
  // opp choose i ways to choose it
  // m * (m - 1) * (m - 2) ways to choose the i pairs
  // then the rest cant match
  // for each remaining pair, remaining * (remaining - 1)
  // for each lamp not in a pair, we can just choose remaining

  for (int i = 0; i <= min(m, pairs); i++) {
    int choices = choose(pairs, i);
    int colors = mul(fact[m], inv(fact[m - i]));
    int ways = mul(choices, colors);
 
    int remaining = m - i;
    if (pairs - i > 0)  {
      if (remaining <= 1) continue;
      ways = mul(ways, binpow(mul(remaining, remaining - 1), pairs - i));
    }

    if (diff > 0) {
      if (remaining == 0) continue;
      ways = mul(ways, binpow(remaining, diff));
    }
      
    ans = add(ans, ways);
  } 
  
  cout << ans << "\n";
}
