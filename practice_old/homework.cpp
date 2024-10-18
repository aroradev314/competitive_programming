// USACO 2017 December P1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
    float n;
    cin >> n;
    vector<float> scores(n);
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        sum += scores[i];
    }

    vector<float> minScore(n);
    minScore[n - 1] = scores[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minScore[i] = std::min(scores[i], minScore[i + 1]);
    }

    float maxScore = std::numeric_limits<float>::min();
    float newSum = sum;
    for (int i = 0; i < n - 2; i++) {
        newSum -= scores[i];
        if ((newSum - minScore[i + 1]) / (n - i - 2) > maxScore) {
			maxScore = (newSum - minScore[i + 1]) / (n - i - 2);
		}
    }
    for (int i = 0; i < n - 2; i++) {
        sum -= scores[i];
        if ((sum - minScore[i + 1]) / (n - i - 2) == maxScore) { 
            cout << i + 1 << endl;
        }
    }
}
