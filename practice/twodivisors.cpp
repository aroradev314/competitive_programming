#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e7 + 10;
int sieve[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < MAX_N; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j < MAX_N; j += i) sieve[j] = i;
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; i++) {
        set<int> div;
        int cur = a[i];
        while (cur > 1) {
            div.insert(sieve[cur]);
            cur /= sieve[cur];
        }
        
        if (div.size() == 1) {
            d1[i] = -1;
            d2[i] = -1;
        }
        else {
            d1[i] = *div.begin();
            d2[i] = 1;
            for (auto it = ++div.begin(); it != div.end(); it++) d2[i] *= *it;
        }
    }

    for (int i = 0; i < n; i++) cout << d1[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) cout << d2[i] << " ";
    
    cout << "\n";
}
