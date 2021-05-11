#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;
stack<int>s;
int main() {
	string str = "+\n";
	int n;
	scanf("%d", &n);
	int cnt = 1;
	string ans = "";
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp >= cnt) {
			while (tmp + 1 != cnt) {
				s.push(cnt++);
				ans += "+\n";
			}
			s.pop();
			ans += "-\n";
		}
		else {
			if (s.top() == tmp) {
				s.pop();
				ans += "-\n";
			}
			else {
				ans = "NO";
				break;
			}
		}
	}
	printf("%s", ans.c_str());
	return 0;
}