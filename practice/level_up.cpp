#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200200;
int fen[MAX_N];

vector<int> rem;

vector<int> lvl[MAX_N], vals[MAX_N];


void add(int num, int p) {
    for (; p < MAX_N; p += (p & -p)) fen[p] += num; 
}

int sum(int p) {
    int ret = 0;
    for (; p > 0; p -= (p & -p)) ret += fen[p];
    return ret;
}

// sum between l and r, inclusive
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        rem.push_back(i);
        lvl[i].push_back(0);
    }

    for (int i = 1; i <= n; i++) add(1, i);

    for (int i = 1; i <= n; i++) {
        vector<int> nrem;

        for (int k : rem) {
            int cur = lvl[k].back();

            int l = cur + 1, r = n;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (sum(cur + 1, mid) >= k) r = mid - 1;
                else l = mid + 1;
            }

            int pos = r + 1;
            
            if (pos <= n) {
                lvl[k].push_back(pos);
                nrem.push_back(k);
            }
        }
        rem = nrem;

        for (int j : vals[i]) add(-1, j);
    }

    // when will we not fight the monster
    // if we level up to a[i] + 1 before i
    while (q--) {
        int i, x;
        cin >> i >> x;
        
        if (lvl[x].size() > a[i] && lvl[x][a[i]] < i) cout << "NO\n";
        else cout << "YES\n";
    }
}
