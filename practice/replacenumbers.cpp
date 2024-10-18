#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 10;

int parent[MAX_N], sz[MAX_N], col[MAX_N], which[MAX_N];
int id[MAX_N];

vector<int> pos[MAX_N];

struct DSU {
    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    } 

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (sz[x] < sz[y]) swap(x, y);
        
        sz[x] += sz[y];
        parent[y] = x;
    }
};

int main() {
    for (int i = 1; i < MAX_N; i++) {
        parent[i] = i;
        col[i] = i;
        sz[i] = 1;
        which[i] = -1;
        id[i] = i;
    }

    DSU dsu;

    int q;
    cin >> q;
    
    // col[x] is what is the color of the xth guy
    // which[x] is which positions have a color of x

    int t, x, y;
    int len = 0;
    while (q--) {
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;

            if (which[x] == -1) { // no positions have this color
                which[x] = id[len];
                
            }
                

        }
    }

    vector<int> ans(len);

    for (int i = 1; i < MAX_N; i++) {
        int c = col[dsu.find(i)];
        for (int j : pos[i]) ans[j] = c;
    }

    for (int i : ans) cout << i << " ";

}
