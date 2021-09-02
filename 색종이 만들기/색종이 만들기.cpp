#include <iostream>
using namespace std;
int paper[129][129];
int ans[2];
void cut(int x, int y, int width) {
	int num = paper[x][y];
	if (width == 1) { ans[num]++; return; }
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + width; j++) {
			if (paper[i][j] != num) {
				cut(x, y, width / 2);
				cut(x, y + width / 2, width / 2);
				cut(x + width / 2, y, width / 2);
				cut(x + width / 2, y + width / 2, width / 2);
				return;
			}
		}
	}
	ans[num]++;
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
	printf("%d\n%d", ans[0], ans[1]);
	return 0;
}