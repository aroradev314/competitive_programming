#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
    	int mn1 = min(a.first, a.second), mn2 = min(b.first, b.second);
    	int mx1 = max(a.first, a.second), mx2 = max(b.first, b.second);
    	if (mn1 == mn2) {
    		return mx1 < mx2;
    	}
    	else return (mn1 < mn2);
    });
	
	for (auto i : arr) cout << i.first << " " << i.second << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    