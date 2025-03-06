#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 210;
int diff[MAX_N][MAX_N];
int hor[MAX_N + 10][MAX_N + 10]; // horizontal prefix sum
int ver[MAX_N + 10][MAX_N + 10]; // vertical prefix sum
int lef[MAX_N + 10];
int above[MAX_N + 10];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	x1++; 
    	x2++;
    	y1++;
    	y2++;
    	x2--;
    	y2--;

    	diff[x1][y1]++;
    	diff[x1][y2 + 1]--;
    	diff[x2 + 1][y1]--;
    	diff[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i < MAX_N - 5; i++) {
    	for (int j = 1; j < MAX_N - 5; j++) {
    		diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
		}    	
    }

    int cur = 0;
    for (int i = 1; i < MAX_N; i++) {
    	for (int j = 1; j < MAX_N; j++) {
    		hor[i][j] += hor[i][j - 1];
    		ver[i][j] += ver[i - 1][j];

    		if (diff[i][j] == k) {
    			hor[i][j]--;
    			ver[i][j]--;
    			cur++;
    		}
    		else if (diff[i][j] == k - 1) {
    			hor[i][j]++;
    			ver[i][j]++;
    		}
    	}
    }

    // for (int i = 1; i < 10; i++) {
    // 	for (int j = 1; j < 10; j++) {
    // 		cout << diff[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    int best = cur;
    for (int l = 1; l < MAX_N; l++) {
    	lef[l] = max(lef[l], lef[l - 1]);
    	for (int r = l; r < MAX_N; r++) {
    		int ans = 0, ans_last = 0;
    		for (int i = 1; i < MAX_N; i++) {
    			int x = hor[i][r] - hor[i][l - 1];
    			ans_last = max(x, x + ans_last);
    			ans = max(ans, ans_last);
    		}
    		best = max(best, cur + ans + lef[l - 1]);
    		lef[r] = max(lef[r], ans);
    	}
    }

    for (int lo = 1; lo < MAX_N; lo++) {
    	above[lo] = max(above[lo], above[lo - 1]);
    	for (int hi = lo; hi < MAX_N; hi++) {
    		int ans = 0, ans_last = 0;
    		for (int i = 1; i < MAX_N; i++) {
    			int x = ver[hi][i] - ver[lo - 1][i];
    			ans_last = max(x, x + ans_last);
    			ans = max(ans, ans_last);
    		}

    		best = max(best, cur + ans + above[lo - 1]);
    		above[hi] = max(above[hi], ans);
    	}
    }

    cout << min(best, 40000);
}

int main() {
	freopen("paintbarn.in", "r", stdin); 
	freopen("paintbarn.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    