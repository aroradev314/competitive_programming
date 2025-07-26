#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 998244353;
const int MAX_N = 5e5 + 10;
int power[MAX_N];
vector<vector<int>> nxt;
vector<int> dp, term;
vector<bool> on;

// dp[node] is how many subsets can make node or lower
// if the current one is on, then any children nodes can either be on or off

void solve() {
    power[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        power[i] = (int) ((power[i - 1] * 2LL) % MOD);
    }

    int n;
    cin >> n;

    nxt.push_back({-1, -1});
    dp.push_back(-1);
    on.push_back(false);
    term.push_back(0);

    int cur = 1;
    while (n--) {
        string s;
        cin >> s;

        int pos = 0;
        vector<int> vis;
        for (int i = 0; i < (int) s.length(); i++) {
            vis.push_back(pos);
            int letter = (s[i] == 'A' ? 0 : 1);
            if (nxt[pos][letter] == -1) {
                nxt.push_back({-1, -1});
                dp.push_back(-1);
                on.push_back(false);
                term.push_back(0);
                nxt[pos][letter] = cur++;
            }
            pos = nxt[pos][letter];
        }

        on[pos] = true;
        vis.push_back(pos);

        while (sz(vis)) {
            pos = vis.back();
            dp[pos] = 0;
            vis.pop_back();

            int first = nxt[pos][0], second = nxt[pos][1];
            if (first != -1 && second != -1) {
                dp[pos] = (int) ((dp[first] * 1LL * dp[second]) % MOD);
                // cout << dp[first] << " " << dp[second] << "\n";
            }
            term[pos] = 0;
            if (first != -1) term[pos] += term[first] + on[first];
            if (second != -1) term[pos] += term[second] + on[second];

            // then we can use this one as well
            if (on[pos]) {
                // cout << "YES\n";
                // if (n == 0 && pos == 2) cout << dp[pos] << " " << term[pos] << endl;
                (dp[pos] += power[term[pos]]) %= MOD;
            }
        }
        cout << dp[0] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
    