#include <stdio.h>
using namespace std;
// 1-based
long long dp[110][110];
int main() {
	int R, C, T;
	int n = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &R, &C);
		for (int i = 1; i <= R; i++) {
			dp[i][1] = 1;
		}
		for (int i = 1; i <= C; i++) {
			dp[1][i] = 1;
		}
		for (int i = 2; i <= R; i++) {
			for (int j = 2; j <= C; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		printf("Case #%d: %lld\n", n, dp[R][C]);
		n++;
	}
	return 0;
}