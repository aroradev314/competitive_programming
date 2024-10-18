#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l = 1, r = 1000;
    while (r - l > 1) {
        int third = l + (r - l) / 3;
        int twothird = r - (r - l) / 3;
        cout << "? " << third << " " << twothird << endl;
        int area;
        cin >> area;
        
        if (area == third * twothird) {
            l = twothird + 1;
        }
        else if (area == third * (twothird + 1)) {
            r = twothird;
            l = third + 1;
        }
        else r = third - 1;
    }
    
    cout << "? 1 " << l << endl;
    int area;
    cin >> area;
    
    int ans;
    if (area != l) ans = l;
    else ans = l + 1;
    
    cout << "! " << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
