#include <stdio.h>
using namespace std;
// 1-based
long long length[81];
int main() {
	int n;
	scanf("%d", &n);
	length[1] = 4;
	length[2] = 6;
	for (int i = 3; i <= n; i++) {
		length[i] = length[i - 1] + length[i - 2];
	}
	printf("%lld", length[n]);
	return 0;
}