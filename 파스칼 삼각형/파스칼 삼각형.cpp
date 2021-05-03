#include <stdio.h>
// 1-based
int pas[32][32];
int main() {
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);
	for (int i = 1; i < 32; i++) {
		pas[i][i] = pas[i][1] = 1;
	}
	for (int i = 1; i < 32; i++) {
		for (int j = 1; j < 32; j++) {
			if (!pas[i][j]) {
				pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
			}
		}
	}
	int ans = 0;
	for (int i = r; i < r + w; i++) {
		for (int j = c; j < c + w; j++) {
			if (i - r >= j - c) {
				ans += pas[i][j];
			}
		}
	}
	printf("%d", ans);
	return 0;
}