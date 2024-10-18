#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

vector<ll> x, left_dist, right_dist;
int n;
ll calc(ll a, ll b, ll mid, ll ind) {
	cout << ind << "       ";
	if (ind >= n || ind < 0) return -1;
	return a * (left_dist[ind] + (mid - x[ind]) * (ind + 1)) + 
		   b * (right_dist[ind] - (mid - x[ind]) * (n - (ind + 1)));
}

int main() {
	cin >> n;
	
	x.resize(n);
	ll l = 2e9, r = -1;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		l = min(l, x[i]);
		r = max(r, x[i]);
	}
	sort(x.begin(), x.end());
	
	left_dist.resize(n);
	right_dist.resize(n);
	for (int i = 1; i < n; i++) {
		right_dist[0] += x[i] - x[0];
	}
	
	for (int i = 1; i < n; i++) {
		left_dist[i] = left_dist[i - 1] + i * (x[i] - x[i - 1]);
		right_dist[i] = right_dist[i - 1] - (n - i) * (x[i] - x[i - 1]);
	}
	
	
	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			
			auto cur = lower_bound(x.begin(), x.end(), mid);
			if (*cur > mid) cur--;
			int ind = distance(x.begin(), cur);
			
			ll cost = calc(a, b, mid, ind);
			ll cost_up = calc(a, b, mid, ind + 1);
			ll cost_down = calc(a, b, mid, ind - 1);
			
			if (cost <= cost_up && cost <= cost_down) {
				cout << cost << "\n";
				break;
			}
			
			if (cost_up < cost) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		cout << endl;
	}
	

}
		
