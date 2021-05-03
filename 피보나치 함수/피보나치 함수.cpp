#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 1000000
using namespace std;
// dp[i]ดย 
vector<pair<int, int>> dp;
int main() {
	int T;
	scanf("%d", &T);
	dp.push_back(make_pair(1, 0));
	dp.push_back(make_pair(0, 1));
	for (int i = 2; i <= 43; i++) {
		dp.push_back(make_pair(dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second));
	}
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", dp[n].first, dp[n].second);
	}
	return 0;
}