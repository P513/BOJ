#include <stdio.h>
#include <algorithm>
using namespace std;
long long time[101010];
long long n, m;
long long num(long long t) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += t / time[i];
	}
	return cnt;
}
int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &time[i]);
	}
	sort(time, time + n);
	long long l = 0;
	long long r = m * time[n - 1];
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		if (num(mid) < m) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf("%lld\n", r);
	return 0;
}