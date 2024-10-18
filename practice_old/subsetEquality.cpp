#include <vector>
#include <iostream>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	
	vector<vector<bool>> matches(19, vector<bool>(26, false));
	for (int i = 0; i < 19; i++) {
		for (int j = i; j < 19; j++) {
			char a = 'a' + i;
			char b = 'a' + j;
			string first = "", second = "";
			for (int k = 0; k < (int) s.length(); k++) {
				if (s[k] == a || s[k] == b) {
					first += s[k];
				}
			}
			for (int k = 0; k < (int) t.length(); k++) {
				if (t[k] == a || t[k] == b) {
					second += t[k];
				}
			}
			if (first == second) {
				matches[i][j] = true;
			}
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		string letters;
		cin >> letters;
		bool works = true;
		for (int i = 0; i < (int) letters.size(); i++) {
			for (int j = i; j < (int) letters.size(); j++) {
				int a = letters[i] - 'a';
				int b = letters[j] - 'a';
				if (!matches[a][b]) {
					works = false;
					break;
				}
			}
		}
		cout << (works ? "Y" : "N");
	}
}

		
