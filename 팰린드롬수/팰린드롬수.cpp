/*
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std; \
int main() {
	while (1) {
		string str;
		char tmp[6];
		scanf("%s", tmp);
		str = tmp;
		queue <int> q;
		stack <int> s;
		if (tmp[0] == '0') { return 0; }
		for (int i = 0; i < str.length(); i++) {
			int j = (int)str[i] - '0';
			q.push(j);
			s.push(j);
		}
		while (!q.empty()) {
			if (q.front() != s.top()) { break; }
			else { q.pop(); s.pop(); }
		}
		if (!q.empty()) {
			printf("no\n");
			while (!q.empty()) {
				q.pop();
				s.pop();
			}
		}
		else {
			printf("yes\n");
		}
	}
}
*/
#include <stdio.h>
int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) { break; }
		int r = 0;
		int tmp = n;
		while (tmp) {
			r *= 10;
			r += tmp % 10;
			tmp /= 10;
		}
		if (r == n) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}