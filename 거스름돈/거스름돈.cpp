#include <stdio.h>
#include <algorithm>
#define MAX 100000
using namespace std;
int dp[100100];
int main() {
	int n;
	scanf("%d", &n);
	dp[1] = dp[3] = MAX;
	dp[2] = dp[5] = 1;
	dp[4] = 2;
	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 5] + 1, dp[i - 2] + 1);
	}
	printf("%d", (dp[n] >= MAX) ? -1 : dp[n]);
	return 0;
}