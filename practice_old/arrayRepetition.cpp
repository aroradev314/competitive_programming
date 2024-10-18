#include <vector>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll LONG_LONG_MAX = (ll) 1e19;

int ind(ll pos, vector<pair<ll, ll>>& rng) {
	int l = 0, r = rng.size();
	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		if (pos >= rng[mid].first && pos <= rng[mid].second) {
			return mid;
		}
		else if (pos < rng[mid].first) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}

void test_case() {
	int n, q;
	cin >> n >> q;
	
	vector<pair<int, int>> ops;
	vector<pair<ll, ll>> rng = {{0, 0}};
	vector<ll> mul = {0};
	map<ll, ll> pos;
	ll total_len = 0;
	for (int i = 0; i < n; i++) {
		int b, x;
		cin >> b >> x;
		
		if (b == 1) {
			ops.push_back({b, x});
		}
		else {
			int len = ops.size();
			if (len > 0 && ops[len - 1].first == 2) {
				if (ops[len - 1].second > LONG_LONG_MAX / (x + 1)) {
					break;
				}
				ops[len - 1].second *= (x + 1);
			}
			else {
				ops.push_back({2, x + 1});
			}
		}
	}
	for (auto& [b, x] : ops) {
		if (b == 1) {
			pos[++total_len] = x;
			rng[rng.size() - 1].second++;
		}
		else {
			rng.push_back({total_len + 1, total_len * x});
			if (total_len > LONG_LONG_MAX / x) {
				break;
			}
			total_len *= x;
			mul.push_back(x);
		}
	}
	
	//cout << endl;
	//for (auto& [l, r] : rng) {
		//cout << l << " " << r << endl;
	//}
	//cout << endl;
	//for (auto& [l, r] : ops) {
		//cout << l << " " << r << endl;
	//}
	//cout << endl;

	while (q--) {
		ll cur;
		cin >> cur;
				
		// cout << rng_pos << " ";
		
		while (true) {
			if (pos.count(cur)) {
				break;
			}
			int i = ind(cur, rng);
			if (i == -1) {
				cout << "ADASDASD";
			}
			ll cur_mul = mul[i];
			
			ll left = 1, right = cur_mul - 1;
			while (left <= right) {
				ll mid = left + (right - left) / 2;				
				ll sub = cur - mid * rng[i - 1].second;
				
				if (sub >= 1 && sub < rng[i].first) {
					cur = sub;
					break;
				}
				else if (sub < 1) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		cout << pos[cur] << " ";
	}
	cout << "\n";
}
			
int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}

