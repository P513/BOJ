#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
queue<pair<int, int>>q;
int maze[101][101], cnt[101][101];
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	q.push(make_pair(1, 1));
	cnt[1][1] = 1;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (maze[a + 1][b] == 1 && a + 1 <= x && cnt[a + 1][b] == 0)
		{
			cnt[a + 1][b] = cnt[a][b] + 1;
			q.push(make_pair(a + 1, b));
		}
		if (maze[a - 1][b] == 1 && a - 1 > 0 && cnt[a - 1][b] == 0)
		{
			cnt[a - 1][b] = cnt[a][b] + 1;
			q.push(make_pair(a - 1, b));
		}
		if (maze[a][b + 1] == 1 && b + 1 <= y && cnt[a][b + 1] == 0)
		{
			cnt[a][b + 1] = cnt[a][b] + 1;
			q.push(make_pair(a, b + 1));
		}
		if (maze[a][b - 1] == 1 && b - 1 > 0 && cnt[a][b - 1] == 0)
		{
			cnt[a][b - 1] = cnt[a][b] + 1;
			q.push(make_pair(a, b - 1));
		}
		if (a == x && b == y)
		{
			printf("%d", cnt[x][y]);
			break;
		}
	}
	return 0;
}