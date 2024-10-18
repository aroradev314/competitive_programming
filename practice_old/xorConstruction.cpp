#include <iostream>
#include <vector>
using namespace std;

int mxXOR(int num, vector<vector<int>>& nxt) {
	int node = 0;
	int ans = 0;
	for (int i = 20; i >= 0; i--) {
		int bit = int(((1 << i) & num) > 0);
		
		if (nxt[node][1 - bit] != 0) {
			node = nxt[node][1 - bit];
			ans += (1 << i);
		}
		else {
			node = nxt[node][bit];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> nums(n - 1);
	for (int i = 0; i < n - 1; i++) cin >> nums[i];
	
	vector<int> pref(n - 1);
	pref[0] = nums[0];
	for (int i = 1; i < n - 1; i++) {
		pref[i] = pref[i - 1] ^ nums[i];
	}
	
	
	vector<vector<int>> nxt(1, vector<int>(2));
	int N = 0;
	
	for (int s : pref) {
		int node = 0;
		for (int i = 20; i >= 0; i--) {
			int bit = int(((1 << i) & s) > 0);
			if (nxt[node][bit] == 0) {
				nxt.push_back(vector<int>(2));
				nxt[node][bit] = ++N;
			}
			node = nxt[node][bit];
		}
	}	
	
	for (int i = 0; i < n; i++) {
		if (mxXOR(i, nxt) > n - 1) continue;
		
		int cur = i;
		cout << cur << " ";
		for (int j : nums) {
			cur = cur ^ j;
			cout << cur << " "; 
		}
		return 0;
	}
	
	cout << -1;
}
