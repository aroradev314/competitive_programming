#include <vector>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		
		vector<bool> visited(n);
		int cur = n - 1;
		bool works = true;
		
		while (k > 0) {
			if (visited[cur]) break;
			visited[cur] = true;
			if (a[cur] > n) {
				works = false;
				break;
			}
			cur -= a[cur];
			if (cur < 0) cur += n;
			k--;
		}
		if (works) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}

				
