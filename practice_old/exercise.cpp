#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		a = a % b;
		if (a == 0) {
			cout << 0 << endl;
			continue;
		}
		int factor = gcd(a, b);
		a /= factor;
		b /= factor;
		
		int copy = b;
		bool impossible = false;
		while (copy > 1) {
			if (copy % 2 == 1) {
				impossible = true;
				break;
			}
			copy /= 2;
		}
		if (impossible) {
			cout << -1 << endl;
			continue;
		}
		
		long long total = 0;
		int bottom = 2;
		int top = 0;
		int slices = 1;
		
		while (bottom <= b) {
			if (top + (b / bottom) > a) {
				bottom *= 2;
				slices = (slices << 1) + 1;
				continue;
			}

			top += (b / bottom);
			total += slices * (b / bottom);
			slices = (slices << 1) + 1;
			bottom *= 2;
		}
		cout << total * factor << endl;
	}
}
