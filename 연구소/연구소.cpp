#include <iostream>
#include <utility>
#include<queue>
#include <vector>
using namespace std;
int n, m;
int safe;
int safe_tmp;
pair <int, int> dir[4] = { make_pair(0,-1),make_pair(0,1),make_pair(-1,0),make_pair(1,0) };
pair <int, int> vir[11];
int check[10][10];
int v[10][10];
int visited[10][10];


void virus(int x, int y) {
	if (visited[x][y] == 0) {
		safe_tmp--;
	}
	visited[x][y] = 2;
	for (int i = 0; i < 4; i++) {
		if (x + dir[i].first < 0 || x + dir[i].first >= n || y + dir[i].second < 0 || y + dir[i].second >= m) {
			continue;
		}
		else if (visited[x + dir[i].first][y + dir[i].second] == 0) {
			virus(x + dir[i].first, y + dir[i].second);
		}
	}
	return;
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = v[i][j];
		}
	}
}

int main() {
	int vir_num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			visited[i][j] = v[i][j];
			if (v[i][j] == 0) {
				safe++;
			}
			else if (v[i][j] == 2) {
				vir[vir_num] = make_pair(i, j);
				vir_num++;
			}
		}
	}
	safe_tmp = safe;
	int ans = 0;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			for (int c = 0; c < n; c++) {
				for (int d = 0; d < m; d++) {
					for (int e = 0; e < n; e++) {
						for (int f = 0; f < m; f++) {
							safe_tmp = safe;
							reset();
							visited[a][b] = 1;
							if (visited[c][d] == 1) {
								continue;
							}
							visited[c][d] = 1;
							if (visited[e][f] == 1) {
								continue;
							}
							visited[e][f] = 1;
							for (int t = 0; t < vir_num; t++) {
								virus(vir[t].first, vir[t].second);
							}
							ans = (ans > safe_tmp ? ans : safe_tmp);
						}
					}
				}
			}
		}
	}

	cout << ans - 3 << endl;
	return 0;
}