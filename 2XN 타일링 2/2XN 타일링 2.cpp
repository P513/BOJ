#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1010];
int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
		dp[i] %= 10007;
	}
	printf("%d", dp[n]);
	return 0;
}