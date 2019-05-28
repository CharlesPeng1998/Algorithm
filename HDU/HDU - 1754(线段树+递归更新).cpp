#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int N, M;
int a[maxn];
int data[3 * maxn];

void Init(int k, int l, int r) {
	if (r - l == 1) data[k] = a[l];
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int m = (l + r) / 2;
		Init(chl, l, m);
		Init(chr, m, r);
		data[k] = max(data[chl], data[chr]);
	}
}

void Update(int i, int j, int k, int l, int r) {
	if (l <= i && i < r) {
		if (r - l == 1) data[k] = j;
		else {
			int chl = 2 * k + 1;
			int chr = 2 * k + 2;
			int m = (l + r) / 2;
			Update(i, j, chl, l, m);
			Update(i, j, chr, m, r);
			data[k] = max(data[chl], data[chr]);
		}
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
		for (int i = 0; i < N; i ++) scanf("%d", a + i);
		memset(data, 0, sizeof data);
		Init(0, 0, N);
		for (int i = 0; i < M; i ++) {
			char inst[2];
			int A, B;
			scanf("%s%d%d", inst, &A, &B);
			if (!strcmp(inst, "U")) Update(A - 1, B, 0, 0, N);
			else printf("%d\n", Query(A - 1, B - 1, 0, 0, N));
		}
	}
	return 0;
}
