#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int ans = min({ (w - x),x,(h - y),y });
	printf("%d", ans);
	return 0;
}