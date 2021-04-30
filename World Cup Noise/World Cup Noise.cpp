#include <stdio.h>
using namespace std;
// 1-based
int dp[46];
int main() {
	int T;
	scanf("%d", &T);
	int num = 1;
	dp[1] = 2; dp[2] = 3;
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		printf("Scenario #%d:\n%d\n\n", num, dp[n]);
		num++;
	}
	return 0;
}