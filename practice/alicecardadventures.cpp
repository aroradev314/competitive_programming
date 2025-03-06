#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> p(3, vector<int>(n + 1));
    for (int i = 0; i < 3; i++) {
    	for (int j = 1; j <= n; j++) cin >> p[i][j];
    } 
	
	vector<char> player(n + 1, '-'); // store how we got to a particular index
	player[1] = 's';
	vector<int> card(n + 1);

	vector<set<pair<int, int>>> s(3);

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) s[i].insert({p[i][j], j});
	}

	set<int> visited;
	visited.insert(1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) s[j].erase({p[j][i], i});
		if (player[i] == '-') continue;

		for (int j = 0; j < 3; j++) {
			while (sz(s[j]) && (*s[j].begin()).first < p[j][i]) {
				int id = (*s[j].begin()).second;
				visited.insert(id);
				if (j == 0) player[id] = 'q';
				else if (j == 1) player[id] = 'k';
				else player[id] = 'j';
				card[id] = i;
				s[j].erase(s[j].begin());
			} 
		}
	}

	if (player[n] == '-') cout << "NO\n";
	else {
		cout << "YES\n";
		int cur = n;
		vector<char> player_traded;
		vector<int> card_traded;
		while (cur != 1) {
			player_traded.push_back(player[cur]);
			card_traded.push_back(cur);
			cur = card[cur];
		}
		reverse(player_traded.begin(), player_traded.end());
		reverse(card_traded.begin(), card_traded.end());
		cout << sz(player_traded) << "\n";
		for (int i = 0; i < sz(player_traded); i++) {
			cout << player_traded[i] << " " << card_traded[i] << "\n";
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
    