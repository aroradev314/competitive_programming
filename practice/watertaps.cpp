#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

const ld DIFF = 1e-12;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, T;
    cin >> n >> T;

    vector<int> aa(n), t(n);
    for (int i = 0; i < n; i++) cin >> aa[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    
    ld x = 0;
    
    vector<pair<int, ld>> hot, cold;
    for (int i = 0; i < n; i++) {
        if (t[i] == T) {
           x += aa[i];
        }
        else if (t[i] > T) {
            hot.push_back({t[i] - T, aa[i]});
        }
        else {
            cold.push_back({T - t[i], aa[i]});
        }
    }

    sort(hot.begin(), hot.end());
    sort(cold.begin(), cold.end());

    int N = hot.size(), M = cold.size();
    int a = 0, b = 0;

    while (a < N && b < M) {
        ld add = min(hot[a].first * hot[a].second, cold[b].first * cold[b].second);
        hot[a].second -= add / hot[a].first;
        cold[b].second -= add / cold[b].first;
        x += add / hot[a].first + add / cold[b].first;
        
        if (hot[a].second < DIFF) a++;
        if (cold[b].second < DIFF) b++;
    }
    
    cout << fixed << setprecision(12) << x;
}
