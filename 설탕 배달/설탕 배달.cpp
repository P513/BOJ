#include <stdio.h>
#include <algorithm>
#define MAX 1700
using namespace std;
int dp[5050];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		dp[i] = MAX;
	}
	dp[3] = 1; dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	printf("%d", (dp[n] >= MAX) ? -1 : dp[n]);
	return 0;
}