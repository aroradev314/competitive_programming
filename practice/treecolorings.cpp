#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 5e5 + 10;
const int INF = 1e9;
vector<int> d[MAX_N];
int dp[MAX_N];

void solve() {
    int x;
    cin >> x;
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}

void preprocess() {
    for (int i = 2; i < MAX_N; i++) {
        for (int j = i; j < MAX_N; j += i) d[j].push_back(i);
    }
    
    for (int i = 0; i < MAX_N; i++) dp[i] = INF;
    dp[1] = 1;
    
    for (int i = 2; i < MAX_N; i++) {
        for (int j : d[i]) {
            dp[i] = min(dp[i], dp[i / j] + dp[j - 2]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    int t;
    cin >> t;
    while (t--) solve();
}
    