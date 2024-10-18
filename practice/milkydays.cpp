#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> diary;

    for (int i = 0; i < n; i++) {
        int d, a;
        cin >> d >> a;
        diary.push_back({d, a});
    }

    int ans = 0;
    deque<pair<int, int>> milk;

    // in the difference between this one and the last one, before adding the milk from this one
    int last = 1e7;
    for (auto [d, a] : diary) {
        int days = max(0, d - last - 1);
        
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
