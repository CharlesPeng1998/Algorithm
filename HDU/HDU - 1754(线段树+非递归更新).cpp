#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 18;
int N, M, n;
int a[maxn];
int data[2 * maxn - 1];

void Init() {  // 将元素的个数扩大到2的幂
	n = 1;
	while (n < N) n *= 2;
	memset(data, 0, sizeof(data));
}

void Update(int k, int s) {
	int v = n - 1 + k; // 实际编号为k的元素在线段树中的节点编号为k + n - 1
	data[v] = s;
	while (v > 0) { // 逐层更新
		v = (v - 1) / 2;
		data[v] = max(data[2 * v + 1], data[2 * v + 2]);
	}
}

int Query(int i, int j, int k, int l, int r) {
	if (r <= i || j < l) return 0; // 区间没有交集
	else if (i <= l && r <= j + 1) return data[k]; // 节点区间[l,r)包含于查询区间[i,j]
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int m = (l + r) / 2;
		return max(Query(i, j, chl, l, m), Query(i, j, chr, m, r));
	}
}

int main() {
	while (~scanf("%d%d", &N, &M)) {
		Init();
		for (int i = 0; i < N; i ++) {
			scanf("%d", a + i);
			Update(i, a[i]);
		}
		for (int i = 0; i < M; i ++) {
			char inst[2];
			int A, B;
			scanf("%s%d%d", inst, &A, &B);
			if (!strcmp(inst, "U")) {
				Update(A - 1, B);
			}
			else printf("%d\n", Query(A - 1, B - 1, 0, 0, n)); // 注意实际元素数量是n不是N！！！
		}
	}
	return 0;
}
