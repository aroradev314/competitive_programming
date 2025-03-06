#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, m; 
    cin >> n >> m;
    multiset<int> a;
    vector<int> b(m);
    int asum = 0, bsum = 0;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	a.insert(x);
    	asum += x;
    } 
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    	bsum += b[i];
    }
    sort(b.begin(), b.end());

    bool works = true;
    for (int i : b) {
    	map<int, int> cur;
    	cur[i] = 1;
    	while (sz(cur) && works) {
    		map<int, int> ncur;
    		for (auto [num, cnt] : cur) {
    			while (cnt && a.count(num)) {
    				a.erase(a.find(num));
    				cnt--;
    			}
    			if (cnt != 0) {
    				if (num == 1) {
    					works = false;
    					break;
    				}
    				else if (num % 2) {
    					ncur[num / 2] += cnt;
    					ncur[num / 2 + 1] += cnt;
    				}
    				else ncur[num / 2] += 2 * cnt;
    			}
    		}
    		cur = ncur;
    	}
    }

    cout << (works && sz(a) == 0 ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    