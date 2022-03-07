// https://www.acmicpc.net/problem/15989
/*
�� ������ DP�� Ǯ����.
�ٽ��� 2�� 3���� �ش� ���� ��Ÿ�� �� �ִ���
*/
#include <iostream>
using namespace std;
int sum[10101];
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i <= 5000; i++) {
		for (int j = 0; j <= 3333; j++) {
			if (i * 2 + j * 3 > 10000)continue;
			sum[i * 2 + j * 3]++;
		}
	}
	sum[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		sum[i] = sum[i] + sum[i - 1];
	}
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", sum[n]);
	}
	return 0;
}