#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    
    vector<vector<int>> adj(n + 1), radj(n + 1);
    vector<int> in(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
        in[b]++;
    }

    queue<int> q;
    vector<int> start;
    vector<int> mark(n + 1);
    for (int i = 1; i <= n; i++) if (in[i] == 0) {
        q.push(i);
        start.push_back(i);
        mark[i] = i;
    }
    
    vector<long long> dp(n + 1);
    long long mx = 0;
    while (q.size() > 0) {
        int cur = q.front();
        // cout << cur << endl;
        q.pop();
        dp[cur] = h[cur];
        for (int i : radj[cur]) {
            if (h[cur] >= h[i]) dp[cur] = max(dp[cur], dp[i] + (h[cur] - h[i]));
            else dp[cur] = max(dp[cur], dp[i] + (k - h[i]) + h[cur]);
        }
        mx = max(mx, dp[cur]);
        for (int i : adj[cur]) {
            in[i]--;
            if (in[i] == 0) q.push(i);
        }
    }
    
    long long ans = mx;
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i + 1;

    sort(p.begin(), p.end(), [&](int a, int b) { return dp[a] < dp[b]; });
    auto cdp = dp;
    for (int i = 0; i < n; i++) {
        int u = p[i];
        
        if (cdp[u] < k) ans = min(ans, mx - cdp[u]);
        if (i + 1 == n) break;
        stack<int> st;
        
        if (cdp[u] < k) {
            st.push(u);
            cdp[u] += k;
        }

        while (!st.empty()) {
            auto on = st.top();
            st.pop();
            mx = max(mx, cdp[on]);
            for (int to : adj[on]) {
                if (cdp[to] < cdp[on]) {
                    if (cdp[to] == dp[to] && cdp[to] + k >= dp[on]) {
                        cdp[to] += k;
                        st.push(to);
                    }
                    else {
                        cout << ans << "\n";
                        return;
                    }
                }
            }
        }

    }


    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
