#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int l = 1, r = n - 1;
    
    int cur = 0, ans = -1;
    int tot = 0;
    while (l < r) {
        cout << l << " " << r << endl;
        int mid = l + (r - l) / 2;
        if ((r - l + 1) % 2 == 0) mid++;
        
        int query = n - (mid + tot) % n;

        cout << "+ " << query << endl;

        tot += query;
        int div; cin >> div;

        if (div == cur) {
            r = mid - 1;
        }
        else {
            l = mid;
            cur++;
        }
    }
    cout << "! " << tot + l;

}
