#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> cur;
    long long sm = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            cur.insert(a[i]);
            sm += a[i];
        }
        else if (sm + a[i] >= 0) {
            sm += a[i];
            cur.insert(a[i]);
        }
        else if (cur.size() && *cur.begin() < a[i]) {
            sm -= *cur.begin();
            sm += a[i];
            cur.erase(cur.begin());
            cur.insert(a[i]);
        }
    }
    cout << cur.size();
}
