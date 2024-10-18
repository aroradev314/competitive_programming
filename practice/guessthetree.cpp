#include <bits/stdc++.h>
using namespace std;

bool wrong = false;

void solve() {
    int n;
    cin >> n;
    set<int> not_seen;
    for (int i = 2; i <= n; i++) not_seen.insert(i);
    
    vector<bool> seen(n + 1);
    seen[1] = true;

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int a = 1, b = *not_seen.begin();

        while (true) {
            cout << "? " << a << " " << b << endl;
            int x;
            cin >> x;
            if (x == -1) {
                wrong = true;
                return;
            }

            if (x == a) {
                seen[b] = true;
                not_seen.erase(b);
                edges.push_back({a, b});
                break;
            }

            if (seen[x]) a = x;
            else b = x;
        }
    }
    cout << "! ";
    for (auto i : edges) cout << i.first << " " << i.second << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- && !wrong) solve();
}
