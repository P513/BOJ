// https://www.acmicpc.net/problem/1890
#include <iostream>
#include <math.h>
using namespace std;
long long map[101][101], visited[101][101], n;
bool check(int x, int y) {
	if (x > n || x<1 || y>n || y < 1)return 0;
	return 1;
}
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &map[i][j]);
		}
	}
	visited[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int jump = map[i][j];
			if (visited[i][j] && map[i][j] > 0) {
				if (check(i + jump, j)) { visited[i + jump][j] += visited[i][j]; }
				if (check(i, j + jump)) { visited[i][j + jump] += visited[i][j]; }
			}
		}
	}
	printf("%lld", visited[n][n]);
	return 0;
}
}