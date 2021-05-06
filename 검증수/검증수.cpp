#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[5];
int main() {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		ans += arr[i] * arr[i];
		ans %= 10;
	}
	printf("%d", ans);
	return 0;
}