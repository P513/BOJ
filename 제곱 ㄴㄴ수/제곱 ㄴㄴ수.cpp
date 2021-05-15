#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
bool arr[1000001];
int sosu[1000001];
int main() {
	long long min, max, tmp;
	scanf("%lld %lld", &min, &max);

	int ans = 0;
	for (long long i = 2; i * i <= max; i++) {
		long long j = i * i;
		if (min % j) { tmp = min + j - min % j; }
		else { tmp = min; }

		while (tmp <= max) {
			arr[tmp - min] = true;
			tmp += j;
		}
	}
	for (long long i = 0; i <= max - min; i++) {
		if (!arr[i]) { ans++; }
	}
	printf("%d", ans);
	return 0;
}