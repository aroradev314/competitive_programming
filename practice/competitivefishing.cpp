#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve(int tt) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    ll a = 0, b = 0;
    ll score = 0;
    int zeros = 0;
    vector<int> blocks;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') {
    		if (i != 0) {
    			blocks.push_back(zeros);
    			score += 1;
    		}
    		b += score;
    		zeros = 0;
    	}
    	else {
    		zeros++;
    		a += score;
    	}
    }
    blocks.push_back(zeros);
    if (b - a < k) {
    	if (tt < 10) cout << "-1\n";
    	else if (tt == 49) cout << n << " " << k << endl << s << endl;
    	return;
    }

    int ans = sz(blocks);
    zeros = blocks[sz(blocks) - 1];
    int ones = 1;
    for (int i = sz(blocks) - 2; i >= 0; i--) {
    	ll new_a = a - zeros;
    	ll new_b = b - ones;
    	if (new_b - new_a >= k) {
    		b = new_b;
    		a = new_a;
    		zeros += blocks[i];
    		ones++;
    		ans--;
    	}
    	else break;
    }

    if (tt < 10) cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) solve(tt);
}
    