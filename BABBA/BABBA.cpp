#include <stdio.h>
int A[46];
int B[46];
int main() {
	int n;
	scanf("%d", &n);
	A[0] = 1; B[0] = 0;
	for (int i = 1; i <= n; i++) {
		A[i] = B[i - 1];
		B[i] = A[i - 1] + B[i - 1];
	}
	printf("%d %d", A[n], B[n]);
	return 0;
}