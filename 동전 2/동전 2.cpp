#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int coin[101], dp[100100];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < k + 1; i++) {
		dp[i] = 100100;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
		dp[coin[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 2; j * coin[i] < k + 1; j++) {
			int next = coin[i] * j;
			dp[next] = j < dp[next] ? j : dp[next];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == 100100) {
		printf("-1");
	}
	else {
		printf("%d\n", dp[k]);
	}
	return 0;
}