#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 2e5 + 10;
int c[MAX_N];
int pref[MAX_N][26];

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    int ans = n;
    for (int _ = 0; _ < 2; _++) {
    	for (int i = 1; i <= n; i++) c[i] = s[i - 1] - 'a';
    	for (int i = 1; i <= n; i++) {
    		for (int j = 0; j < 26; j++) pref[i][j] = pref[i - 1][j];
    		pref[i][c[i]]++;
    	}


    	int cur = 1;
    	while (cur <= n / 2 && c[cur] == c[n - cur + 1]) cur++;
    	if (cur > n / 2) {
    		ans = 0;
    		break;
    	}

    	int l = cur, r = n - cur + 1;
    	int mid = 0;
    	while (c[n / 2 - mid] == c[n / 2 + mid 	+ 1]) mid++;
    	vector<int> a(26), b(26);
    	bool works = true;
    	for (int j = 0; j < 26; j++) {
    		a[j] = pref[n / 2][j] - pref[l - 1][j];
    		b[j] = pref[r][j] - pref[n / 2][j];
    		if (a[j] != b[j]) works = false;
    	}
    	if (mid && works) {
    		ans = min(ans, (r - l + 1) / 2 - mid);
    		continue;
    	}

    	for (int i = n / 2; i <= r; i++) {
    		vector<int> diff(26), our(26);
    		for (int j = 0; j < 26; j++) {
    			our[j] = pref[i][j] - pref[l - 1][j];
    			diff[j] = pref[r][j] - pref[i][j];
    		}
    	 	works = true;
    		for (int j = 0; j < 26; j++) if (our[j] < diff[j]) works = false;
    		if (works) {
    			ans = min(ans, i - l + 1);
    			break;
    		}
    	}

    	reverse(s.begin(), s.end());
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
    