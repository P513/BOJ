#include <stdio.h>
using namespace std;
int dp[31][31];
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= 30; i++) {
		dp[i][i] = 1;
		dp[1][i] = i;
	}
	while (T--) {
		int east, west;
		scanf("%d %d", &east, &west);
		for (int i = 2; i <= east; i++) {
			for (int j = i + 1; j <= west; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}
		printf("%d\n", dp[east][west]);
	}
	return 0;
}