#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

bool works;

void solve() {
    int n;
    cin >> n;

    cout << "mul 9" << endl;
    int res;
    cin >> res;
    cout << "digit" << endl;
    cin >> res;
    cout << "digit" << endl;
    cin >> res;
    cout << "add " << n - 9 << endl;
    cin >> res;
    cout << "!" << endl;
    cin >> res;

    if (res == -1) works = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    works = true;
    while (t-- && works) solve();
}
    