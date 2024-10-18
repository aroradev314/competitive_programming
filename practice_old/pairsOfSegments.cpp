// Educational Codeforces Round 150
// D
#include <vector>
#include <iostream>
using namespace std;

bool intersects(pair<int, int>& a, pair<int, int>& b) {
	return ((a.first <= b.first && a.second >= b.first) || (b.first <= a.first && b.second >= a.first));
}

bool compareSecond(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return p1.second < p2.second;
}

void test_case() {
	int n;
	cin >> n;
	vector<pair<int, int>> seg(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		seg[i] = {a, b};
	}
	
	vector<pair<int, int>> unions;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (intersects(seg[i], seg[j])) {
				unions.push_back({min(seg[i].first, seg[j].first), max(seg[i].second, seg[j].second)});
			}
		}
	}
	
	sort(unions.begin(), unions.end(), compareSecond);
	
	int maxRight = -1;
	int pairCnt = 0;
	
	for (int i = 0; i < (int) unions.size(); i++) {
		if (unions[i].first > maxRight) {
			pairCnt++;
			maxRight = unions[i].second;
		}
	}
	cout << n - 2 * pairCnt << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		test_case();
	}
}



