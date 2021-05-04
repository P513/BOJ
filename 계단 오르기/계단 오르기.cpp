#include <stdio.h>
#include <algorithm>
using namespace std;
int stair[3030];
int dp[3030][3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}
	dp[1][1] = stair[1];
	dp[1][2] = 0;
	dp[2][1] = dp[1][1] + stair[2];
	dp[2][2] = stair[2];
	for (int i = 3; i <= n; i++) {
		dp[i][1] = dp[i - 1][2] + stair[i];
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + stair[i];
	}
	printf("%d", max(dp[n][1], dp[n][2]));
	return 0;
}