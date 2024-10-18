// 2017 US Open P3
#include <vector>
#include <iostream>
using namespace std;

int n;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int topLeftI, topLeftJ, bottomLeftI, bottomLeftJ;

void dfs(vector<vector<int>>& visited, vector<string>& image, char color, int colorNum, int i, int j) {
	visited[i][j] = colorNum;
	for (int dir = 0; dir < 4; dir++) {
		int newI = i + di[dir];
		int newJ = j + dj[dir];
		if (newI >= topLeftI && newI <= bottomLeftI && newJ >= topLeftJ && newJ <= bottomLeftJ && !visited[newI][newJ] && image[newI][newJ] == color) {
			dfs(visited, image, color, colorNum, newI, newJ);
		}
	}
}

bool contin(vector<string>& image, int color1, int color2) {
	vector<vector<int>> visited(n, vector<int>(n));
	bool found = false;
	for (int i = topLeftI; i <= bottomLeftI; i++) {
		for (int j = topLeftJ; j <= bottomLeftJ; j++) {
			if (image[i][j] == color1) {
				dfs(visited, image, color1, 1, i, j);
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}
	found = false;
	for (int i = topLeftI; i <= bottomLeftI; i++) {
		for (int j = topLeftJ; j <= bottomLeftJ; j++) {
			if (image[i][j] == color2) {
				dfs(visited, image, color2, 2, i, j);
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}
	
	bool works1 = true, works2 = false;
	for (int i = topLeftI; i <= bottomLeftI; i++) {
		for (int j = topLeftJ; j <= bottomLeftJ; j++) {
			if (image[i][j] == color1 && visited[i][j] != 1) {
				works1 = false;
			}
			if (image[i][j] == color2 && visited[i][j] != 2) {
				works2 = true;
			}
		}
	}
	return works1 && works2;
}

pair<char, char> hasTwoColors(vector<string>& image) {
	char color1 = '.', color2 = '.';
	for (int i = topLeftI; i <= bottomLeftI; i++) {
		for (int j = topLeftJ; j <= bottomLeftJ; j++) {
			if (image[i][j] == color1 || image[i][j] == color2) {
				continue;
			}
			if (color1 == '.') {
				color1 = image[i][j];
			}
			else if (color2 == '.') {
				color2 = image[i][j];
			}
			else {
				return {'.', '.'};
			}
		}
	}
	if (color1 != '.' && color2 != '.') {
		return {color1, color2};
	}
	else {
		return {'.', '.'};
	}
}
				

int main() {
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);
	cin >> n;
	vector<string> image(n);
	for (int i = 0; i < n; i++) {
		cin >> image[i];
	}
	vector<vector<int>> ans;
	for (topLeftI = 0; topLeftI < n; topLeftI++) {
		for (topLeftJ = 0; topLeftJ < n; topLeftJ++) {
			for (bottomLeftI = topLeftI; bottomLeftI < n; bottomLeftI++) {
				for (bottomLeftJ = topLeftJ; bottomLeftJ < n; bottomLeftJ++) {
					pair<char, char> colors = hasTwoColors(image);
					if (colors.first != '.') {
						if (contin(image, colors.first, colors.second) || contin(image, colors.second, colors.first)) {
							ans.push_back({topLeftI, topLeftJ, bottomLeftI, bottomLeftJ});
						}
					}
				}
			}
		}
	}
	
	int num = ans.size();
	for (int i = 0; i < (int) ans.size(); i++) {
		vector<int> current = ans[i];
		for (int j = 0; j < (int) ans.size(); j++) {
			vector<int> other = ans[j];
			if (j != i && other[0] <= current[0] && other[1] <= current[1] && other[2] >= current[2] && other[3] >= current[3]) {
				num--;
				break;
			}
		}
	}
	cout << num << endl;
}
	
	
