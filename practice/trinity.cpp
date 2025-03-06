#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
	
	int ans = n - 1;
    for (int i = 1; i < n; i++) {
    	int cur = n - i - 1; // how many we need to switch
    	int l = 1, r = i - 1;
    	while (l <= r) {
    		int mid = l + (r - l) / 2;
    		if (a[mid] + a[mid - 1] > a[i]) r = mid - 1;
    		else l = mid + 1;
    	}
    	ans = min(ans, cur + r);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    