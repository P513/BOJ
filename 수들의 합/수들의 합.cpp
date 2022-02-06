#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	long long s;
	scanf("%lld", &s);
	long long cnt = 0, sum = 0;
	for (long long i = 1; i <= s; i++) {
		sum += i;
		if (sum > s) {
			printf("%lld\n", cnt);
			return 0;
		}
		else if (sum == s) {
			printf("%lld\n", cnt + 1);
			return 0;
		}
		else {
			cnt++;
		}
	}
	return 0;
}