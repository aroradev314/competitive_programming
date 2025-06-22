#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ap(k), bp(k);
    int x;
    for (int i = 0; i < k; i++) {
    	cout << "? " << i + 1 << endl;
    	cin >> x;
    	ap[i % k] = x - 1;
    }
    for (int i = 0; i < k; i++) {
    	cout << "? " << (n - 1) - i + 1 << endl;
    	cin >> x;
    	bp[(n - 1 - i) % k] = x - 1;
    }
    // if bp[i] = x, then at the ith position we have x

	int diff = -1;
	for (int i = 0; i < k; i++) {
		if (ap[i] != bp[i]) {
			diff = i;
			break;
		}
	}

	if (2 * k == n) {
		cout << "! " << k << " " << k << endl;
		return;
	}
	if (diff == -1) {
		cout << "! -1" << endl;
		return;
	}
	// for (int i : ap) cout << i << " ";
	// cout << endl;
	// for (int i : bp) cout << i << " ";
	// cout << endl;

	// check where the difference could be
	vector<int> possible;
	for (int i = diff; i < n; i += k) possible.push_back(i);

	int l = 0, r = sz(possible) - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		cout << "? " << possible[mid] + 1 << endl;
		cin >> x, x--;

		if (x == ap[diff]) l = mid + 1;
		else r = mid - 1;
 	}
 	// cout << "done binary" << endl;

 	int cur = possible[l - 1];
 	vector<int> section(k);
 	section[0] = ap[diff];
 	for (int i = 1; i < k; i++) {
 		cout << "? " << cur + i + 1 << endl;
 		cin >> x, x--;

 		section[i] = x;
 	}

 	vector<bool> av(k), bv(k);
 	for (int i = 0; i < k; i++) {
 		if (section[i] == ap[(cur + i) % k] && i + cur < n - k) av[i] = true;
 		else break;
 	}
 	for (int i = k - 1; i >= 0; i--) {
 		if (section[i] == bp[(cur + i) % k] && i + cur > k - 1) bv[i] = true;
 		else break;
 	}

 	int last = 0;
 	for (int i = 0; i < k; i++) {
 		if (av[i] && bv[i]) {
 			cout << "! -1" << endl;
 			return;
 		}
 		if (av[i]) last++;
 	}

 	cout << "! " << cur + last << " " << n - (cur + last) << endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    