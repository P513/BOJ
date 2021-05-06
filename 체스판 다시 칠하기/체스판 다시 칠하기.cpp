#include <stdio.h>
#include <algorithm>
using namespace std;
char board[51][51];
int check(int x, int y) {
	int num = 0;
	// 0 0ÀÌ BLACK
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (board[i][j] == 'B' && (i + j) % 2 == 0) {
				num++;
			}
			else if (board[i][j] == 'W' && (i + j) % 2 == 1) {
				num++;
			}
		}
	}
	return min(num, 64 - num);
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}
	int ans = n * m + 1;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int num = check(i, j);
			ans = min(ans, num);
		}
	}
	printf("%d", ans);
	return 0;
}