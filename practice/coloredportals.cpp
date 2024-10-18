#include <bits/stdc++.h>
using namespace std;

int val(char c) {
    if (c == 'B') return 0;
    else if (c == 'R') return 1;
    else if (c == 'G') return 2;
    else return 3;
}

void ckmin(int& num, int check) {
    if (num == -1 || check < num) num = check;
}

void ckmax(int& num, int check) {
    if (num == -1 || check > num) num = check;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> col(n + 1);

    map<int, int> m;
    int l = 0;
    for (int i = 0; i < (1 << 4); i++) {
        if (__builtin_popcount(i) == 2) m[i] = l++;
    }

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        col[i] += (1 << val(s[0]));
        col[i] += (1 << val(s[1]));
    }

    map<int, int> last;
    vector<int> bef(n + 1, -1), after(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int cur = col[i];
        int opp = 0;
        for (int j = 0; j < 4; j++) if (!(cur & (1 << j))) opp += (1 << j);

        for (auto& [k, v] : last) if (k != cur && k != opp) ckmax(bef[i], v);
        last[cur] = i;
    }
    
    last.clear();
    for (int i = n; i >= 1; i--) {
        int cur = col[i];
        int opp = 0;
        for (int j = 0; j < 4; j++) if (!(cur & (1 << j))) opp += (1 << j);

        for (auto& [k, v] : last) if (k != cur && k != opp) ckmin(after[i], v);
        last[cur] = i;
    }
    
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);

        int ans = -1;

        for (int i = 0; i < 4; i++) if ((col[x] & (1 << i)) && (col[y] & (1 << i))) ans = y - x;
        
        if (bef[y] >= x) ckmin(ans, y - x);
        if (bef[x] != -1) ckmin(ans, (x - bef[x]) + (y - bef[x]));
        if (after[y] != -1) ckmin(ans, (after[y] - y) + (after[y] - x));

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
