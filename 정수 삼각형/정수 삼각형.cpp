#include <stdio.h>
#include <algorithm>
using namespace std;
int pyramid[505][505];
int dp[505][505];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &pyramid[i][j]);
		}
	}
	dp[1][1] = pyramid[1][1];
	dp[2][1] = dp[1][1] + pyramid[2][1];
	dp[2][2] = dp[1][1] + pyramid[2][2];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (!dp[i][j]) {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + pyramid[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	printf("%d", ans);
	return 0;
}