#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1010];
int dp[1010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int ans = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int tmp = (arr[i] > arr[j] ? dp[j] + 1 : 1);
			dp[i] = max(dp[i], tmp);
		}
		ans = (ans < dp[i]) ? dp[i] : ans;
	}

	printf("%d", ans);
	return 0;
}