#include <stdio.h>
// 1-based
int square[50626];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 226; i++) {

		printf("§\n");
		square[i*i] = 1;
	}
	return 0;
}