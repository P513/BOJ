#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int tile[1010];
int main() {
	int n;
	scanf("%d", &n);
	tile[1] = 1;
	tile[2] = 2;
	tile[3] = 3;
	for (int i = 4; i <= n; i++) {
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 10007;
	}
	printf("%d", tile[n]);
}
