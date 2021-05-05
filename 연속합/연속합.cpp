#include <stdio.h>
#include <algorithm>
using namespace std;
int num[100100];
int dp[100100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	int max = -100000001;
	for (int i = 1; i <= n; i++) {
		dp[i] = ((dp[i - 1] > 0) ? dp[i - 1] : 0) + num[i];
		max = (max < dp[i]) ? dp[i] : max;
	}
	printf("%d", max);
	return 0;
}