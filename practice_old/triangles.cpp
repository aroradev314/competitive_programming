// USACO Feb 2020 Silver P2

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#define f first
#define s second
using namespace std;

int MOD = 1e9 + 7;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].f >> points[i].s;
	}
	
	map<pair<int, int>, long long> xDist, yDist;
	sort(points.begin(), points.end());
	
	long long total = 0;
	int start = 0, elements;
	for (int i = 1; i < n; i++) {
		if (points[i].f == points[i - 1].f) {
			total += points[i].s - points[start].s;
		}
		else {
			yDist[points[start]] = total;
			elements = (i - 1) - start + 1;
			for (int j = start + 1; j <= i - 1; j++) {
				int diff = points[j].s - points[j - 1].s;
				int left = j - start;
				int right = elements - left - 1;
				total -= diff;
				total += diff * left;
				total -= diff * right;
				total %= MOD;
				yDist[points[j]] = total;
			}
			total = 0;
			start = i;
		}
	}
	yDist[points[start]] = total;
	elements = (n - 1) - start + 1;
	for (int j = start + 1; j <= n - 1; j++) {
		int diff = points[j].s - points[j - 1].s;
		int left = j - start;
		int right = elements - left - 1;
		total -= diff;
		total += diff * left;
		total -= diff * right;
		total %= MOD;
		yDist[points[j]] = total;
	}
	
		
	total = 0;
	start = 0;
	sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
		return (a.second != b.second) ? a.second < b.second : a.first < b.first;
	});
	
	for (int i = 1; i < n; i++) {
		if (points[i].s == points[i - 1].s) {
			total += points[i].f - points[start].f;
		}
		else {
			xDist[points[start]] = total;
			elements = (i - 1) - start + 1;
			for (int j = start + 1; j <= i - 1; j++) {
				int diff = points[j].f - points[j - 1].f;
				int left = j - start;
				int right = elements - left - 1;
				total -= diff;
				total += diff * left;
				total -= diff * right;
				total %= MOD;
				xDist[points[j]] = total;
			}
			total = 0;
			start = i;
		}
	}
	xDist[points[start]] = total;
	elements = (n - 1) - start + 1;
	for (int j = start + 1; j <= n - 1; j++) {
		int diff = points[j].f - points[j - 1].f;
		int left = j - start;
		int right = elements - left - 1;
		total -= diff;
		total += diff * left;
		total -= diff * right;
		total %= MOD;
		xDist[points[j]] = total;
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += xDist[points[i]] * yDist[points[i]];
		ans %= MOD;
	}
	cout << ans << endl;
}
	
		
		
	
			
	
	
	
	
