#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    // so we have fl and fr, sl and sr
    // we loop through the powers of 2 backwards
    // see if one can be a 0 and the other can be a 1

	int l, r;
	cin >> l >> r;

    int fl = l, sl = l;
    int fr = r, sr = r;

    int first = 0, second = 0;
    for (int i = 30; i >= 0; i--) {
    	int pow = 1 << i;
    	if (fr > sr) {
    		swap(fl, sl);
    		swap(fr, sr);
    		swap(first, second);
    	}
    	if (fl <= pow && sr >= pow) {
    		second += pow;
    		sr -= pow;
    		sl -= pow;
    	}
    	else if (sl <= pow && fr >= pow) {
    		first += pow;
    		fr -= pow;
    		fl -= pow;
    	}
		if (fl >= pow) {
    		first += pow;
    		fl -= pow;
    		fr -= pow;
    	}
    	if (sl >= pow) {
    		second += pow;
    		sl -= pow;
    		sr -= pow;
    	}
    }
    assert(first != second);

    if (first > second) swap(first, second);

    int third = -1;
    if (first > l) third = l;
    else if (second < r) third = r;
    else third = first + 1;

    // int prod = (first ^ second) + (first ^ third) + (second ^ third);
    // cout << prod << "\n";

    cout << first << " " << second << " " << third << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    