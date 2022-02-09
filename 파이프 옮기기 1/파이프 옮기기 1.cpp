#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int map[20][20];
int ans, n;
// d[0]���� d[1]���� d[2]�밢��
vector<pair<int, int>>d[3] = { {make_pair(0,1),make_pair(1,1)},
	{make_pair(1,0),make_pair(1,1)},
	{make_pair(1,0),make_pair(0,1),make_pair(1,1)} };
int check(int x, int y, int dir) {
	if (x > n || y > n) {
		return 0;
	}
	else if (map[x][y] == 1) {
		return 0;
	}
	if (dir == 2) {
		if (map[x][y - 1] || map[x - 1][y]) {
			return 0;
		}
	}
	return 1;
}
void dfs(int x, int y, int dir) {
	if (x == n && y == n) {
		ans++;
		return;
	}
	// ���� ����
	if (dir == 0) {
		// ���� ����
		if (check(x + d[0][0].first, y + d[0][0].second, 0)) {
			dfs(x + d[0][0].first, y + d[0][0].second, dir);
		}
		// ���� �밢
		if (check(x + d[0][1].first, y + d[0][1].second, 2)) {
			dfs(x + d[0][1].first, y + d[0][1].second, 2);
		}
	}
	// ���� ����
	else if (dir == 1) {
		// ���� ����
		if (check(x + d[1][0].first, y + d[1][0].second, 1)) {
			dfs(x + d[1][0].first, y + d[1][0].second, dir);
		}
		// ���� �밢
		if (check(x + d[1][1].first, y + d[1][1].second, 2)) {
			dfs(x + d[1][1].first, y + d[1][1].second, 2);
		}
	}
	// ���� �밢��
	else {
		// ���� ����
		if (check(x + d[2][0].first, y + d[2][0].second, 1)) {
			dfs(x + d[2][0].first, y + d[2][0].second, 1);
		}
		// ���� ����
		if (check(x + d[2][1].first, y + d[2][1].second, 0)) {
			dfs(x + d[2][1].first, y + d[2][1].second, 0);
		}
		// ���� �밢
		if (check(x + d[2][2].first, y + d[2][2].second, 2)) {
			dfs(x + d[2][2].first, y + d[2][2].second, 2);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(1, 2, 0);
	printf("%d\n", ans);
	return 0;
}