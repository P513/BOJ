#include <stdio.h>
#include <algorithm>
#define MAX 1000000
using namespace std;
// dp[i]�� i�� 1�� ����� �ּ� ���� Ƚ��
int dp[1001000];
int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		dp[i] = min(dp[i / 3] + i % 3, dp[i / 2] + i % 2)+1;
	}
	printf("%d", dp[n]);
	return 0;
}