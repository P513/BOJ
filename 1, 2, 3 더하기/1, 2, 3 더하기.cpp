#include <stdio.h>
#include <algorithm>
#define MAX 1000000
using namespace std;
// dp[i]는 i를 1,2,3의 합으로 나타내는 방법의 수
int dp[12];
int main() {
	int T;
	scanf("%d", &T);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}