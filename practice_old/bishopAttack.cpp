#include <vector>
#include <iostream>
using namespace std;

int main() {
	int row;
	char letter;
	
	cin >> letter >> row;
	
	int col = letter - 'a';
	
	row--;
	int total = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (abs(i - row) == abs(j - col)) {
				total++;
			}
		}
	}
	
	cout << total;
}

	
