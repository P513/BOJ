#include <stdio.h>
// dp[i]는 i번째 피보나치 수
int dp[22];
int fibo(int n) {
	if (n == 0 || n == 1)return n;
	if (dp[n] != 0)return dp[n];
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;	dp[1] = 1; dp[2] = 1;
	fibo(n);
	printf("%d", dp[n]);
	return 0;
}