/* 1��° �ڵ� 
#include <stdio.h>
// dp[i]�� i��° �Ǻ���ġ ��
long long dp[900];
long long fibo(int n) {
	if (n == 0) return 0;
	if (n == 1)return 1;
	if (dp[n] != 0)return dp[n];
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;	dp[1] = 1; dp[2] = 1;
	fibo(n);
	printf("%lld", dp[n]);
	return 0;
}
*/
/* 2��° �ڵ�
#include <stdio.h>
// dp[i]�� i��° �Ǻ���ġ ��
long long dp[900];
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;	dp[1] = 1; dp[2] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld", dp[n]);
	return 0;
}
*/