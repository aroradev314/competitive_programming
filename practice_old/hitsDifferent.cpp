// Codeforces 871 (Div 4) 

#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

ll ans[2000007];
ll a[1500][1500] = {}, curr = 1;
	
int main() {
	int t;
	cin >> t;
	for (int i = 1; i < 1500; i++) {
		for (int j = i - 1; j >= 1; j--) {
			a[j][i - j] = a[j - 1][i - j] + a[j][i - j - 1] - a[j - 1][i - j - 1] + curr * curr;
			ans[curr] = a[j][i - j];
			curr++;
		}
	}
	
	while (t--) {
		ll n; 
		cin >> n;
		cout << ans[n] << endl;
	}
	
}
