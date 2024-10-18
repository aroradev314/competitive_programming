#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAX_N = 1e7;
bool prime[MAX_N + 10];
int pref[MAX_N + 10];

void solve() {
    int n;
    cin >> n;

    int ans = pref[n] + (n >= 5 ? 1 : 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 2; i <= MAX_N; i++) prime[i] = true;

    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) for (int j = i + i; j <= MAX_N; j += i) prime[j] = false;
    }

    for (int i = 3; i <= MAX_N; i++) pref[i] = pref[i - 1] + (prime[i] && prime[i - 2] ? 1 : 0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
