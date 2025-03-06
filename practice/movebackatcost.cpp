#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cur;
    for (int i = 0; i < n; i++) {
    	while (sz(cur) && a[cur.back()] > a[i]) cur.pop_back();
    	cur.push_back(i);
    } 
    vector<bool> chosen(n);
    while (sz(cur)) {
    	chosen[cur.back()] = true;
    	cur.pop_back();
    }

    vector<int> first, second;
    for (int i = 0; i < n; i++) {
    	if (chosen[i]) first.push_back(a[i]);
    	else second.push_back(a[i]);
    }
    sort(second.begin(), second.end());
    if (sz(second) == 0) {
    	for (int i : first) cout << i << " ";
    	cout << "\n";
    	return;
    }

    vector<int> ans;
    int x = 0, y = 0;
    while (x < sz(first) && first[x] <= second[y] + 1) {
    	ans.push_back(first[x]);
    	x++;
    }

    while (x < sz(first) && y < sz(second)) {
    	if (first[x] < second[y]) {
    		ans.push_back(first[x] + 1);
    		x++;
    	}
    	else {
    		ans.push_back(second[y] + 1);
    		y++;
    	}
    }

    while (x < sz(first)) {
    	ans.push_back(first[x] + 1);
    	x++;
    }

    while (y < sz(second)) {
    	ans.push_back(second[y] + 1);
    	y++;
    }


    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    