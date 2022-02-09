#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string>v[20] = { {"0","1","2","3","4","5","6","7","8","9"} };
int main() {
	long long n;
	scanf("%lld", &n);
	long long cnt = 9;
	if (n <= 9) {
		printf("%d", stoi(v[0][n]));
		return 0;
	}
	if (n > 1022) {
		printf("-1");
	}
	// 자리 수
	for (long long i = 1; i < 20; i++) {
		// 1~9 붙이기
		for (long long j = 1; j < 10; j++) {
			for (long long k = 0; k < v[i - 1].size(); k++) {
				long long idx = i - 1;
				string tmp3 = v[idx][k];
				long long t = stoll(v[idx][k]);
				while (t / 10) {
					t /= 10;
				}
				if (t < j) {
					string tmp = v[idx][k];
					string a = to_string(j);
					v[i].push_back(a + tmp);
					cnt++;
					if (cnt == n) {
						string tmp2 = v[i][v[i].size() - 1];
						printf("%lld", stoll(tmp2));
						return 0;
					}
				}
			}
		}
	}
	return 0;
}