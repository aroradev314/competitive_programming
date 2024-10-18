#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    
    
    while (t--) {
        int b, h;
        cin >> b >> h;
        
        double hyp = sqrt(b * b + h * h);
        
        if (int(hyp) == hyp) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}

        
        
