#include <stdio.h>
using namespace std;
long long prime[1010101];
long long num_nonsquare(long long n) {
	long long ans = 0;
	for (long long i = 1; i * i <= n; i++) {
		ans += prime[i] * (n) / (i * i);
	}
	return ans;
}
int main() {
	prime[1] = 1;
	for (int i = 1; i < 1010101; i++) {
		for (int j = 2 * i; j < 1010101; j += i) {
			prime[j] -= prime[i];
		}
	}
	long long n;
	scanf("%lld", &n);
	long long left = 0;
	long long right = 1e12;
	while (left + 1 < right) {
		long long mid = (left + right) / 2;
		if (num_nonsquare(mid) < n) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%lld", right);
	return 0;
}