#include <stdio.h>
long long str[10000];
int main() {
	int T;
	scanf("%d", &T);
	int num = 1;
	while (T--) {
		long long cons, vow, length;
		scanf("%lld %lld %lld", &cons, &vow, &length);
		str[1] = vow; str[2] = vow * vow + cons * vow;
		for (int i = 3; i <= length; i++) {
			str[i] = (str[i - 2] * cons * vow + str[i - 1] * vow) % 1000000007;
		}
		printf("Case #%d: %lld\n", num, str[length]);
		num++;
	}
}