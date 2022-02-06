#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
pair<int, int>house[101];
vector<pair<int, int>>chicken;

int main() {
	int house_cnt = 0, chicken_cnt = 0;
	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house[house_cnt++] = make_pair(i, j);
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
				chicken_cnt++;
				map[i][j] = 0;
			}
		}
	}
	int chicken_path = 2100000000;
	vector<int> is_chicken(chicken_cnt, 0);
	for (int i = 0; i < m; i++) {
		is_chicken[i] = 1;
	}
	do {
		int path_sum = 0;
		int path = 2100000000;
		for (int i = 0; i < house_cnt; i++) {
			path = 2100000000;
			for (int j = 0; j < chicken_cnt; j++) {
				if (is_chicken[j] == 1) {
					int tmp = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
					path = path > tmp ? tmp : path;
				}
			}
			path_sum += path;
		}
		chicken_path = path_sum > chicken_path ? chicken_path : path_sum;
	} while (prev_permutation(is_chicken.begin(), is_chicken.end()));
	cout << chicken_path << endl;
	return 0;
}