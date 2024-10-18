// 2020 US Open P2
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#define MAXN 100001
using namespace std;

int x[MAXN], y[MAXN], cid[MAXN];
int minl[MAXN], maxr[MAXN];

bool cmp(int a, int b) {
	if (x[a] == x[b]) return y[a] < y[b];
	return x[a] < x[b];
}

int main() {
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		cid[i] = i;
	}
	sort(cid, cid + n, cmp);
	minl[0] = y[cid[0]];
	for (int i = 1; i < n; i++) {
		minl[i] = min(minl[i - 1], y[cid[i]]);
	}
	maxr[n - 1] = y[cid[n - 1]];
	for (int i = n - 2; i >= 0; i--) {
		maxr[i] = max(maxr[i + 1], y[cid[i]]);
	}
	int ans = 1;
	for (int i = 0; i < n - 1; i++) {
		if (minl[i] > maxr[i + 1]) {
			ans++;
		}
	}
	cout << ans << endl;
}
			


				
	
	
	
	


