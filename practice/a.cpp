#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    if (s.length() == 1) {
      char x = (s[0] == 'a' ? 'b' : 'a');
      cout << s << x << "\n";
    }
    else {
      char first = s[0], second = s[1];
      char cur = 'a';
      while (cur == first || cur == second) cur++;
      cout << s[0] << cur << s[1];
      for (int i = 2; i < s.length(); i++) cout << s[i];
      cout << "\n";
    }
  }

}
