 #include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    // if i < j and a[i] < a[j], there is no way to update a[j] first
    // so if the target b[j] > b[i], it must be less, and then more in one turn 
    // every x must also be <= mn 

    bool works = true;
    
    int mn = b[0];
    for (int i = 1; i < n; i++) {
        if (b[i] > mn + (mn - 1)) {
            works = false;
            break;
        }
        mn = min(mn, b[i]);
    }

    cout << (works ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    