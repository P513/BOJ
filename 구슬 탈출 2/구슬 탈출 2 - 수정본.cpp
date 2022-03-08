#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int rx, ry, bx, by, step;
	Info(int rx, int ry, int bx, int by, int step) :rx(rx), ry(ry), bx(bx), by(by), step(step) {}
};

int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool chk[10][10][10][10];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int rx, ry, bx, by;
	char map[10][11];
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R')rx = i, ry = j;
			else if (map[i][j] == 'B')bx = i, by = j;
		}
	}
	queue<Info> q;
	q.push(Info(rx, ry, bx, by, 0));
	chk[rx][ry][bx][by] = true;

	int ans = -1;
	while (!q.empty() && ans < 0) {
		if (q.front().step >= 10)break;
		for (int i = 0; i < 4; i++) {
			/*
				나랑 코드를 다르게 작성한 점은,
				1) 먼저 빨간 공과 파란 공이 홀에 빠지는지 확인한다
				2) 이동 후 둘이 겹치는지를 확인한다
			*/
			bool rchk = false, bchk = false;
			rx = q.front().rx, ry = q.front().ry, bx = q.front().bx, by = q.front().by;
			while (map[rx + dx[i]][ry + dy[i]] != '#') {
				rx += dx[i], ry += dy[i];
				if (map[rx][ry] == 'O')rchk = true;
			}
			while (map[bx + dx[i]][by + dy[i]] != '#') {
				bx += dx[i], by += dy[i];
				if (map[bx][by] == 'O')bchk = true;
			}
			if (bchk)continue;
			else if (rchk) {
				ans = q.front().step + 1;
				break;
			}
			// 겹치는 경우
			if (rx == bx && ry == by) {
				if (i == 0) {
					if (q.front().ry < q.front().by)ry--;
					else by--;
				}
				else if (i == 1) {
					if (q.front().rx < q.front().bx)rx--;
					else bx--;
				}
				else if (i == 2) {
					if (q.front().ry < q.front().by)by++;
					else ry++;
				}
				else {
					if (q.front().rx < q.front().bx)bx++;
					else rx++;
				}
			}
			if (!chk[rx][ry][bx][by]) {
				q.push(Info(rx, ry, bx, by, q.front().step + 1));
			}
		}
		q.pop();
	}
	printf("%d\n", ans);
	return 0;
}