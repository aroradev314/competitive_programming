#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(const vector<int> &x, const vector<int> &y) {
		return x[2] > y[2];
	}
};

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int>> times(n);
	vector<int> current;
	for (int i = 0; i < n; i++) {
		current = vector<int>(3);
		cin >> current[0] >> current[1];
		current[2] = i;
		times[i] = current;
		
	}
	sort(times.begin(), times.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	int i = 1;
	int maxWait = 0;
	int currentTime = times[0][0] + times[0][1];
	while (i < n || pq.size() > 0) {
		while (i < n && times[i][0] <= currentTime) {
			pq.push(times[i]);
			i++;
		}
		if (pq.size() == 0) {
			pq.push(times[i]);
			currentTime = times[i][0];
			i++;
		}
		vector<int> now = pq.top();
		pq.pop();
		maxWait = max(maxWait, currentTime - now[0]);
		currentTime += now[1];
	}
	cout << maxWait << endl;
}
		
		
