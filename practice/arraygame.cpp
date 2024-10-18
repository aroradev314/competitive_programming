#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int lb = 0;
    while (lb < n - 1 && a[lb] < a[lb + 1]) lb++;
    int rb = n - 1;
    while (rb > 0 && a[rb] < a[rb - 1]) rb--;

    int l = 0, r = n - 1;
    bool alice = true, found = false;

    while (l <= r && l <= lb && r >= rb) {
        int ldist = lb - l + 1;
        int rdist = r - rb + 1;
        if (a[l] == a[r]) {
            if (ldist % 2 == 0 && rdist % 2 == 0) alice = !alice;
            found = true;
            break;
        }
        else if (a[l] < a[r]) {
            if (rdist % 2) {
                found = true;
                break;
            }
            l++;
        }
        else {
            if (ldist % 2) {
                found = true;
                break;
            }
            r--;
        }
        alice = !alice;
    }
    
    if (!found) {
        int dist = max(lb - l + 1, rb - r + 1);
        if (dist % 2 == 0) alice = !alice;
    }
    cout << (alice ? "Alice\n" : "Bob\n");
}
