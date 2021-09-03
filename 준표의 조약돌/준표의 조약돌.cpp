#include <iostream>
#include <string>
using namespace std;
char path[300300];
int main() {
	int n, b_num, w_num;
	scanf("%d %d %d", &n, &b_num, &w_num);
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &path[i]);
	}
	int lo = 1, hi = 0, b = 0, w = 0, ans = 0;
	while (hi < n + 1) {
		if (b > b_num) {
			if (path[lo] == 'B') b--;
			else w--;
			lo++;
		}
		else if (w < w_num) {
			hi++;
			if (path[hi] == 'B') {
				b++;
			}
			else {
				w++;
			}
		}
		else if (w >= w_num && b <= b_num) {
			ans = ans > hi - lo + 1 ? ans : hi - lo + 1;
			hi++;
			if (path[hi] == 'B') {
				b++;
			}
			else {
				w++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}