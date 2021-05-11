#include <stdio.h>
#include <iostream>
using namespace std;
int num[10100];
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 1;
	for (int i = 666; i <= 2000000000; i++) {
		int tmp = i;
		while (tmp > 665) {
			if (tmp % 1000 == 666) {
				num[cnt] = i; cnt++;
				break;
			}
			else { tmp /= 10; }
		}
		if (cnt == n + 1) { break; }
	}
	printf("%d", num[n]);
	return 0;
}