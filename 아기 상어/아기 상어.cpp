/*
			DFS로 풀면 한~~~~~~참 걸림
			BFS를 이용하세용
*/
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
pair<int, int>d[4] = { make_pair(0,1),make_pair(0,-1), make_pair(1,0), make_pair(-1,0) };
vector<vector<int>> space(21, vector<int>(21, 0));
int n;
int ans = 0;
int level = 2;
int level_up = 2;
int visited[21][21];
int tmp_dist = 100000000;
queue<pair<int, int>> q;

pair<int, int> find_fish(int find_x, int find_y) {
	int dist = 100000000;
	int dist_x = -1;
	int dist_y = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 물고기 먹을 수 있으면
			if (space[i][j] < level&& space[i][j] != 0) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						if (x + d[t].first<0 || x + d[t].first>n - 1 || y + d[t].second<0 || y + d[t].second>n - 1) {
							continue;
						}
						if (visited[x + d[t].first][y + d[t].second] > 0) {
							continue;
						}
						if (x + d[t].first == find_x && y + d[t].second == find_y) {
							tmp_dist = visited[x][y] > tmp_dist ? tmp_dist : visited[x][y];
						}
						if (space[x + d[t].first][y + d[t].second] > level) {
							continue;
						}
						visited[x + d[t].first][y + d[t].second] = visited[x][y] + 1;
						q.push(make_pair(x + d[t].first, y + d[t].second));
					}
				}
				dist_x = tmp_dist < dist ? i : dist_x;
				dist_y = tmp_dist < dist ? j : dist_y;
				dist = tmp_dist < dist ? tmp_dist : dist;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						visited[i][j] = 0;
					}
				}
				tmp_dist = 100000000;
			}
		}
	}
	if (dist_x > -1) {
		ans += dist;
	}
	pair<int, int> dist_pair = make_pair(dist_x, dist_y);
	return dist_pair;
}

int main() {
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}
	pair<int, int>dir;
	while (dir.first >= 0 && dir.second >= 0) {
		dir = find_fish(x, y);
		if (dir.first < 0) {
			break;
		}
		space[dir.first][dir.second] = 9;
		space[x][y] = 0;
		x = dir.first;
		y = dir.second;
		level_up--;
		if (level_up == 0 && level != 9) {
			level += 1;
			level_up = level;
		}
	}
	cout << ans << endl;
	return 0;
}