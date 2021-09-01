#include <iostream>
#include <string>
using namespace std;
int paper[2200][2200];
int ans[3];

void cut(int x, int y, int dist) {
	int tmp = paper[x][y];
	if (dist == 1) { ans[tmp + 1]++; return; }
	for (int i = x; i < x + dist; i++) {
		for (int j = y; j < y + dist; j++) {
			if (tmp != paper[i][j]) {
				cut(x, y, dist / 3);
				cut(x + dist / 3, y, dist / 3);
				cut(x + dist * 2 / 3, y, dist / 3);
				cut(x, y + dist / 3, dist / 3);
				cut(x + dist / 3, y + dist / 3, dist / 3);
				cut(x + dist * 2 / 3, y + dist / 3, dist / 3);
				cut(x, y + dist * 2 / 3, dist / 3);
				cut(x + dist / 3, y + dist * 2 / 3, dist / 3);
				cut(x + dist * 2 / 3, y + dist * 2 / 3, dist / 3);
				return;
			}
		}
	}
	ans[tmp + 1]++;
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	cut(0, 0, n);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}