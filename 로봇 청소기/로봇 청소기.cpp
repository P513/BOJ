#include <iostream>
#include <utility>
using namespace std;
pair<int, int>dir[4] = { make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1) };
int map[100][100];
int cleaned = 0;
int n, m, r, c, d;

void clean(int x, int y, int d) {
	map[x][y] = 2;
	int tmp;
	int turn = 0;
	for (int i = 1; i < 5; i++) {
		tmp = d - i >= 0 ? d - i : d - i + 4;
		int dir_x = dir[tmp].first;
		int dir_y = dir[tmp].second;
		if (map[x + dir_x][y + dir_y] == 1) {
			cleaned++;
			clean(x + dir_x, y + dir_y, tmp);
			break;
		}
		else {
			turn = i == 4 ? 1 : 0;
			continue;
		}
	}
	if (turn && x - dir[d].first > 0 && y - dir[d].second > 0 && x - dir[d].first <= n
		&& y - dir[d].second <= m && map[x - dir[d].first][y - dir[d].second] != 0) {
		clean(x - dir[d].first, y - dir[d].second, d);
	}
	return;
}

int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			// 벽은 0, 청소할 곳은 1, 청소한 곳은 2
			map[i][j] = abs(map[i][j] - 1);
		}
	}
	r++; c++;
	if (map[r][c] == 1)cleaned = 1;
	clean(r, c, d);
	cout << cleaned << endl;
	return 0;
}