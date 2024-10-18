#include <vector>
#include <iostream>
using namespace std;

constexpr int MAX_N = 2e5 + 5;
constexpr int MAX_JMP = 18;

int up[MAX_JMP + 1][MAX_N];

int jmp(int a, int b) {
	for (int i = 0; i <= MAX_JMP; i++) {
		if ((1 << i) & b) {
			a = up[i][a];
		}
	}
	return (a ?: - 1);
}

int main() {
	int n, q;
	cin >> n >> q;
	
	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		up[0][i] = a;
	}
	
	for (int i = 1; i <= MAX_JMP; i++) {
		for (int x = 2; x <= n; x++) {
			up[i][x] = up[i - 1][up[i - 1][x]];
		}
	}
	
	for (int i = 0; i < q; i++) {
		int x, k;
		cin >> x >> k;
		cout << jmp(x, k) << endl;
	}
}

		
		
		
	
	
	
	
	
	
	
