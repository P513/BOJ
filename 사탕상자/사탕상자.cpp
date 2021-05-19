#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int node_num;
// n순위에 해당하는 사탕의 맛(index) 찾기
long long findIndex(vector<long long>& tree, int node, int left, int right, int num) {
	// 해당하는 index를 찾음
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (2 * node <= node_num && tree[node * 2] >= num) {
		return findIndex(tree, 2 * node, left, mid, num);
	}
	num -= tree[node * 2];
	// 구간합이 찾는 순위보다 작으면 오른쪽 탐색
	if (2 * node + 1 <= node_num && tree[node * 2 + 1] >= num) {
		return findIndex(tree, 2 * node + 1, mid + 1, right, num);
	}
}

// tree[index] = val 일 때 해당 범위 update
void update(vector<long long>& tree, int node, int left, int right, int index, long long value) {
	if (!(left <= index && index <= right))return;
	tree[node] += value;
	if (left != right) {
		int mid = (left + right) / 2;
		update(tree, node * 2, left, mid, index, value);
		update(tree, node * 2 + 1, mid + 1, right, index, value);
	}
}

int main() {
	// 0~1e6개의 사탕
	int h = (int)ceil(log2(1e6));
	// 전체 노드의 개수 = 2^(h+1) - 1
	node_num = (1 << (1 + h));
	vector<long long> tree(node_num);
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			// b에 해당하는 index 찾고 update
			long long index = findIndex(tree, 1, 0, 1e6 - 1, b);
			printf("%lld\n", index);
			update(tree, 1, 0, 1e6 - 1, index, -1);
		}
		else {
			scanf("%d %d", &b, &c);
			// 해당 index(b)의 value(c) update
			update(tree, 1, 0, 1e6 - 1, b, c);
		}
	}
	return 0;
}