#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    k *= 2;
    l *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	a[i] *= 2;
    } 

    int pos = k, cur = 1, time = a[0];
    while (cur < n && pos < l) {
    	while (cur < n && a[cur] < pos)  {
    		pos = max(pos, min(pos, a[cur] + time) + k);
    		cur++;
    	}
    	if (cur >= n) break;

    	if (a[cur] - pos <= time) pos += k;
    	else {
    		int sc = a[cur] - time;
    		int meet = (pos + sc) / 2;
    		time += meet - pos;
    		pos = meet + k;
    	}
    	cur++;
    }

    if (pos < l) time += l - pos;

    cout << time << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    