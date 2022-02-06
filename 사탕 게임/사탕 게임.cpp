#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string>s;
/*int x[4] = { 0,0,-1,1 };
int y[4] = { 1,-1,0,0 };*/
int x[2] = { 0,1 };
int y[2] = { 1,0 };
int count(int n) {
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		char candy = s[i][0];
		int candy_cnt = 1;
		for (int j = 1; j < n; j++) {
			if (candy == s[i][j]) {
				candy_cnt++;
				tmp = tmp < candy_cnt ? candy_cnt : tmp;
			}
			else {
				candy = s[i][j];
				tmp = tmp < candy_cnt ? candy_cnt : tmp;
				candy_cnt = 1;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		char candy = s[0][j];
		int candy_cnt = 1;
		for (int i = 1; i < n; i++) {
			if (candy == s[i][j]) {
				candy_cnt++;
				tmp = tmp < candy_cnt ? candy_cnt : tmp;
			}
			else {
				candy = s[i][j];
				tmp = tmp < candy_cnt ? candy_cnt : tmp;
				candy_cnt = 1;
			}
		}
	}
	return tmp;
}
int main() {
	int n;
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		s.push_back(input);
	}
	int is = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < 2; t++) {
				if (i + x[t] < 0 || i + x[t] >= n || j + y[t] < 0 || j + y[t] >= n || s[i + x[t]][j + y[t]] == s[i][j]) {
					continue;
				}
				else {
					// 왼쪽, 위를 두 번 확인해야 할 이유가?
					int tmp = s[i][j];
					s[i][j] = s[i + x[t]][j + y[t]];
					s[i + x[t]][j + y[t]] = tmp;
					int cmp = count(n);
					is = 1;
					ans = ans < cmp ? cmp : ans;
					tmp = s[i][j];
					s[i][j] = s[i + x[t]][j + y[t]];
					s[i + x[t]][j + y[t]] = tmp;
				}
			}
		}
	}
	int cmp = count(n);
	ans = ans < cmp ? cmp : ans;
	printf("%d", ans);
	return 0;
}