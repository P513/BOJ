#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 500000
using namespace std;
vector <int> v;
int square[50050];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 225; i++) {
		v.push_back(i * i);
	}
	for (int i = 1; i <= n; i++) {
		int MIN = MAX;
		for (int j = 0; v[j] <= i; j++) {
			if (i == v[j]) { MIN = 0; break; }
			else { MIN = min(MIN, square[i - v[j]]); }
		}
		square[i] = MIN + 1;
	}
	printf("%d", square[n]);
	return 0;
}