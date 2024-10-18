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

    stack<pair<int, int>> greater, less;
    greater.push({1e9, -1});
    less.push({-1, -1});
    
    // count how many arrays where the current element is the biggest or the smallest
    // if there are ties how do we avoid overcounting
    // subtract all the times that this element was the minimum value 

    vector<vector<int>> mn(n, vector<int>(2));
    vector<vector<int>> mx(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        while (greater.top().first <= a[i]) greater.pop();
        while (less.top().first >= a[i]) less.pop();
        mx[i][0] = greater.top().second + 1;
        mn[i][0] = less.top().second + 1;
        
        greater.push({a[i], i});
        less.push({a[i], i});
    }

    while (sz(greater)) greater.pop();
    while (sz(less)) less.pop();
    
    greater.push({1e9, n});
    less.push({-1, n});
    for (int i = n - 1; i >= 0; i--) {
        while (greater.top().first < a[i]) greater.pop();
        while (less.top().first > a[i]) less.pop();
        mx[i][1] = greater.top().second - 1;
        mn[i][1] = less.top().second - 1;
        
        greater.push({a[i], i});
        less.push({a[i], i});
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * 1LL * (i - mx[i][0] + 1) * (mx[i][1] - i + 1); 
        ans += a[i] * (-1LL) * (i - mn[i][0] + 1) * (mn[i][1] - i + 1); 
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
