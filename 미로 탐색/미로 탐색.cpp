#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
int visited[101][101], map[101][101], ans, n, m, cnt;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
queue<tuple<int, int, int>>q;

int check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return 0;
	if (map[x][y] == 0)return 0;
	if (visited[x][y] == 1)return 0;
	return 1;
}
void bfs(int x, int y, int cnt) {
	if (x == n - 1 && y == m - 1) { ans = cnt + 1; return; }
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i], next_y = y + dy[i];
		if (check(next_x, next_y)) {
			visited[next_x][next_y] = 1;
			q.push(make_tuple(next_x, next_y, cnt + 1));
		}
	}
	while (!q.empty()) {
		int next_x = get<0>(q.front());
		int next_y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();
		bfs(next_x, next_y, cnt);
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	// 1이 이동 가능
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	visited[0][0] = 1;
	bfs(0, 0, 0);
	printf("%d", ans);
	return 0;
}