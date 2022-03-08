// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <math.h>
#include<queue>
#include<utility>
using namespace std;
char board[20][20];
int n, m, ans = 111;
// -1(검은공이 먼저) 0(아무거나) 1(빨간공이 먼저)
int located(int bx, int by, int rx, int ry, int dir) {
	switch (dir) {
		// 위
	case 1:
		if (rx < bx) return 1;
		else if (rx == bx) return 0;
		else return -1;
		// 아래
	case 2:
		if (rx < bx) return -1;
		else if (rx == bx)return 0;
		else return 1;
		// 왼쪽
	case 3:
		if (ry < by) return 1;
		else if (ry == by)return 0;
		else return -1;
		// 오른쪽
	case 4:
		if (ry < by)return -1;
		else if (ry == by)return 0;
		else return 1;
	}
}
bool check(int x, int y, int cx, int cy) {
	if (x < 0 || x >= n || y < 0 || y >= m)return 0;
	else if (x == cx && y == cy)return 0;
	else if (board[x][y] == '#') return 0;
	else if (board[x][y] == '.') return 1;
	else return 0;
}
bool hole(int x, int y) {
	if (board[x][y] == 'O')return 1;
	return 0;
}
pair<int, int> slide(pair<int, int>cur, pair<int, int>other, int dir) {
	int x = cur.first, y = cur.second;
	int cx = other.first, cy = other.second;
	switch (dir) {
		//위
	case 1:
		while (1) {
			x--;
			if (hole(x, y)) { return make_pair(-1, -1); }
			if (!check(x, y, cx, cy)) { return make_pair(x + 1, y); }
		}
		// 아래	
	case 2:
		while (1) {
			x++;
			if (hole(x, y)) { return make_pair(-1, -1); }
			if (!check(x, y, cx, cy)) { return make_pair(x - 1, y); }
		}
		// 왼
	case 3:
		while (1) {
			y--;
			if (hole(x, y)) { return make_pair(-1, -1); }
			if (!check(x, y, cx, cy)) { return make_pair(x, y + 1); }
		}
		// 오
	case 4:
		while (1) {
			y++;
			if (hole(x, y)) { return make_pair(-1, -1); }
			if (!check(x, y, cx, cy)) { return make_pair(x, y - 1); }
		}
	}
}

int main() {
	queue<pair<int, int>>r_info, b_info;
	queue<int>c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &board[i][j]);
			if (board[i][j] == 'B') {
				b_info.push(make_pair(i, j));
				board[i][j] = '.';
			}
			else if (board[i][j] == 'R') {
				r_info.push(make_pair(i, j));
				board[i][j] = '.';
			}
		}
	}
	c.push(1);
	while (!r_info.empty() && !b_info.empty()) {
		int rx = r_info.front().first, ry = r_info.front().second;
		int bx = b_info.front().first, by = b_info.front().second;
		int cnt = c.front();
		r_info.pop(); b_info.pop(); c.pop();
		if (cnt > 10)continue;
		//위
		int ball = located(bx, by, rx, ry, 1);
		// 빨
		if (ball > 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 1);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 1);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else if (ball == 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 1);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 1);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		// 파
		else {
			pair<int, int>b = slide(make_pair(bx, by), make_pair(rx, ry), 1);
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(b.first, b.second), 1);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		//아래
		ball = located(bx, by, rx, ry, 2);
		if (ball > 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 2);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 2);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else if (ball == 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 2);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 2);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else {
			pair<int, int>b = slide(make_pair(bx, by), make_pair(rx, ry), 2);
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(b.first, b.second), 2);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		//왼
		ball = located(bx, by, rx, ry, 3);
		if (ball > 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 3);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 3);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else if (ball == 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 3);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 3);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else {
			pair<int, int>b = slide(make_pair(bx, by), make_pair(rx, ry), 3);
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(b.first, b.second), 3);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		//오
		ball = located(bx, by, rx, ry, 4);
		if (ball > 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 4);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 4);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else if (ball == 0) {
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(bx, by), 4);
			pair<int, int>b = slide(make_pair(bx, by), make_pair(r.first, r.second), 4);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
		else {
			pair<int, int>b = slide(make_pair(bx, by), make_pair(rx, ry), 4);
			pair<int, int>r = slide(make_pair(rx, ry), make_pair(b.first, b.second), 4);
			if (b.first < 0 && b.second < 0) {}
			else if (r.first < 0 && r.second < 0) { ans = min(ans, cnt); }
			else {
				r_info.push(make_pair(r.first, r.second));
				b_info.push(make_pair(b.first, b.second));
				c.push(cnt + 1);
			}
		}
	}

	if (ans > 10) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
	return 0;
}