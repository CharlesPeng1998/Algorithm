#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
int ans[maxn];
struct Node {
	int l, r, v, lazy;
} tree[maxn * 4];
int T, k, Q;

void Init(int k, int l, int r) {
	tree[k].l = l;
	tree[k].r = r;
	tree[k].v = tree[k].lazy = 0;
	if (l == r) return;
	int chl = k << 1;
	int chr = k << 1 | 1;
	int m = (l + r) / 2;
	Init(chl, l, m);
	Init(chr, m + 1, r);
}

void PushUp(int k) { // 向上往父节点方向更新数据
	tree[k].v = max(tree[k << 1].v, tree[k << 1 | 1].v);
}

void PushDown(int k) {
	int chl = k << 1;
	int chr = k << 1 | 1;
	tree[chl].lazy += tree[k].lazy;
	tree[chl].v += tree[k].lazy;
	tree[chr].lazy += tree[k].lazy;
	tree[chr].v += tree[k].lazy;
	tree[k].lazy = 0;
}

void Update(int k, int l, int r) {
	if (l == tree[k].l && r == tree[k].r) {
		tree[k].v += 1;
		tree[k].lazy += 1;
		return;
	}
	if (tree[k].lazy) PushDown(k);
	int m = (tree[k].l + tree[k].r) / 2;
	if (l > m) Update(k << 1 | 1, l, r);
	else if (m >= r) Update(k << 1, l, r);
	else {
		Update(k << 1, l, m);
		Update(k << 1 | 1, m + 1, r);
	}
	PushUp(k);
}

int Query(int k, int l, int r) {
	if (l == tree[k].l && r == tree[k].r) {
		return tree[k].v;
	}
	if (tree[k].lazy) PushDown(k);
	int m = (tree[k].l + tree[k].r) / 2;
	if (m < l) return Query(k << 1 | 1, l, r);
	else if (m >= r) return Query(k << 1, l, r);
	else {
		return max(Query(k << 1, l, m), Query(k << 1 | 1, m + 1, r));
	}
}

int main() {
	int cnt = 1;
	scanf("%d", &T);
	while (T --) {
		int len = 0;
		memset(ans, 0, sizeof ans);
		scanf("%d%d", &k, &Q);
		Init(1, 1, 1000000);
		int a, b;
		for (int i = 0; i < Q; i ++) {
			scanf("%d%d", &a, &b);
			if (Query(1, a, b - 1) < k) {
				ans[len ++] = i + 1;
				Update(1, a, b - 1);
			}
		}
		printf("Case %d:\n", cnt ++);
		for (int i = 0; i < len; i ++) printf("%d ", ans[i]);
		printf("\n\n");
	}

	return 0;
}
