#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e5 + 10;
bool prime[MAX_N];

void solve() {
    int n;
    cin >> n;

    vector<bool> used(n + 1);
    for (int i = n / 3; i <= n; i++) {
    	if (prime[i]) {
    		cout << i << " ";
    		used[i] = true;
    		int cur = 1;
    		while (true) {
    			if (i - cur < 1) break;
    			cout << i - cur << " ";
    			used[i - cur] = true;
    			if (i + cur > n) break;
    			cout << i + cur << " ";
    			used[i + cur] = true;
    			cur++;
    		}
    		for (int j = 1; j <= n; j++) if (!used[j]) cout << j << " ";
    		cout << "\n";
    		break;
    	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < MAX_N; i++) prime[i] = true;
    for (int i = 2; i < MAX_N; i++) {
    	if (prime[i]) {
    		for (int j = i + i; j < MAX_N; j += i) prime[j] = false;
    	}
    }

    int t;
    cin >> t;
    while (t--) solve();
}
    