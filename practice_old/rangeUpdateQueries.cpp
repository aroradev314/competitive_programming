#include <vector>
#include <iostream>
using namespace std;
const int N = 2e5 + 10;  // limit for array size
int n, q;  // array size
long long t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, long long value) {  // set value at position p
  for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

long long query(int l, int r) {  // sum on interval [l, r)
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
	cin >> n >> q;
	
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	for (int i = 1; i <= n; i++) {
		t[i + n - 1] = nums[i] - nums[i - 1];
	}
	build();
	
	int type, a, b, u;
	long long k;
	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b >> k; a--; b--;
			modify(a, k);
			if (b + 1 < n) {
				modify(b + 1, -k);
			}
		}
		else {
			cin >> u;
			cout << query(0, u) << endl;
		}
	}
	
}
