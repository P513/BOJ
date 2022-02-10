#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int visited[1010];
vector <int> graph[1010];
queue<int>q;
void dfs(int n) {
	visited[n] = 1;
	printf("%d ", n);
	for (int next : graph[n]) {
		if (visited[next] == 0) {
			dfs(next);
		}
	}
}
void bfs(int n) {
	visited[n] = 1;
	printf("%d ", n);
	for (int next : graph[n]) {
		if (visited[next] == 0) {
			q.push(next);
		}
	}
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		if (visited[next] == 0) {
			bfs(next);
		}
	}
	return;
}
int main() {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	printf("\n");
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}
	bfs(v);
	return 0;
}