// 2020 US Open P1
#include <vector>
#include <algorithm>
#include <iostream>
#define f first
#define s second
#define ll long long
using namespace std;

ll next(vector<ll>& start, vector<ll>& finish, ll pos, ll dist) {
	auto closestEnd = lower_bound(finish.begin(), finish.end(), pos + dist);
	if (closestEnd == finish.end()) {
		return -1L;
	}
	int ind = closestEnd - finish.begin();
	return max(pos + dist, start[ind]);
}

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> grass(m);
	for (int i = 0; i < m; i++) {
		cin >> grass[i].f >> grass[i].s;
	}
	sort(grass.begin(), grass.end());
	
	vector<ll> start(m), finish(m);
	for (int i = 0; i < m; i++) {
		start[i] = grass[i].f;
		finish[i] = grass[i].s;
	}
	
	ll l = 1, r = 1e18 + 1;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		bool ok = true;
		ll pos = start[0];
		for (int i = 0; i < n - 1; i++) {
			pos = next(start, finish, pos, mid);
			if (pos == -1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l - 1 << endl;
}

		
				
	
	
	
	

