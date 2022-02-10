#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
int visited[101][101], my, enemy, n, m, cnt;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
char war[101][101];
queue<pair<int, int>> q;
char ch;
int check(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0)return 0;
	if (visited[x][y])return 0;
	if (war[x][y] != ch)return 0;
	return 1;
}

void bfs(int x, int y) {
	cnt++;
	for (int i = 0; i < 4; i++) {
		if (check(x + dx[i], y + dy[i])) {
			visited[x + dx[i]][y + dy[i]] = 1;
			q.push(make_pair(x + dx[i], y + dy[i]));
		}
	}
	while (!q.empty()) {
		int nx = q.front().first, ny = q.front().second;
		q.pop();
		bfs(nx, ny);
	}
	return;
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &war[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				ch = war[i][j];
				if (war[i][j] == 'W') {
					cnt = 0;
					bfs(i, j);
					my += cnt * cnt;
				}
				else {
					cnt = 0;
					bfs(i, j);
					enemy += cnt * cnt;
				}
			}
		}
	}
	printf("%d %d\n", my, enemy);
	return 0;
}