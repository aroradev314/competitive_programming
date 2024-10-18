#include <vector>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

struct Patch {
	int loc, score;
	
	const bool operator<(Patch other) const {
		return loc < other.loc;
	}
};


int main() {
	int k, m, n;
	cin >> k >> m >> n;
	
	vector<Patch> patches(k);
	for (int i = 0; i < k; i++) {
		cin >> patches[i].loc >> patches[i].score;
	}
	sort(patches.begin(), patches.end());
	
	vector<int> other(m);
	for (int i = 0; i < m; i++) {
		cin >> other[i];
	}
	sort(other.begin(), other.end());
	
	multiset<ll> ones, twos;
	
	int l = 0, r = k - 1;
	ll edge = 0;
	while (l < k && patches[l].loc < other[0]) {
		edge += patches[l].score;
		l++;
	}
	ones.insert(edge);
	edge = 0;
	
	while (r >= 0 && patches[r].loc > other[m - 1]) {
		edge += patches[r].score;
		r--;
	}
	ones.insert(edge);
	
	vector<int> closest(m, 2e9);
	
	for (int i = l; i <= r; i++) {
		cout << patches[i].loc << " ";
		auto near = lower_bound(other.begin(), other.end(), patches[i].loc);
		if (near != other.end()) {
			closest[i] = *near;
		}
		if (near != other.begin()) {
			near--;
			if (abs(*near - patches[i].loc) < abs(closest[i] - patches[i].loc)) {
				closest[i] = *near;
			}
		}
	}
	
	for (int i = 0; i < m - 1; i++) {
		int l = 0, r = 
		
	

}
	
	
	
	
	


	
