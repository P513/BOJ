#include <stdio.h>
#include <algorithm>
using namespace std;
int val[1010][3];
int dp[1010][3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &val[i][0], &val[i][1], &val[i][2]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + val[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + val[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + val[i][2];
	}
	printf("%d", min(min(dp[n][0], dp[n][1]), dp[n][2]));
	return 0;
}