#include <stdio.h>
using namespace std;
long long prime[1000001];
// 어떤 수의 제곱으로 나눠지는 수들 중 n번째 수를 구하자
long long num_squarefree(long long n) {
	long long ans = 0;
	for (long long i = 1; i * i <= n; i++) {
		ans += prime[i] * n / (i * i);
	}
	return ans;
}
int main() {
	prime[1] = 1;
	for (long long i = 1; i < 1000001; i++) {
		for (long long j = i * 2; j < 1000001; j += i) {
			prime[j] -= prime[i];
		}
	}
	long long n;
	scanf("%lld", &n);
	long long min = 0, max = 1e12;
	// parametric search, 시간복잡도 O(log n)
	while (min + 1 < max) {
		long long mid = (min + max) / 2;
		if (mid - num_squarefree(mid) < n) {
			min = mid;
		}
		else {
			max = mid;
		}
	}
	printf("%lld", max);
}