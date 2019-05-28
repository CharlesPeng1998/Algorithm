// 需要lazy处理 不然TLE

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

typedef long long ll;
const int maxn = 100005;
int N, Q;
struct Node {
	int l, r;
	ll lazy; // 这个要long long 否则WA
	ll v;
} tree[4 * maxn];
int a[maxn];

void Init(int k, int l, int r) {
	if (l == r) {
		tree[k].v = a[l];
		tree[k].l = l;
		tree[k].r = r;
		tree[k].lazy = 0;
	}
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int mid = (l + r) / 2;
		Init(chl, l, mid);
		Init(chr, mid + 1, r);
		tree[k].v = tree[chl].v + tree[chr].v;
		tree[k].l = l;
		tree[k].r = r;
		tree[k].lazy = 0;
	}
}

void PushDown(int k) {
	int chl = 2 * k + 1;
	int chr = 2 * k + 2;
	int mid = (tree[k].l + tree[k].r) / 2;
	tree[chl].v += (mid - tree[k].l + 1) * tree[k].lazy;
	tree[chr].v += (tree[k].r - mid) * tree[k].lazy;
	tree[chl].lazy += tree[k].lazy; // 注意是 +=
	tree[chr].lazy += tree[k].lazy;
	tree[k].lazy = 0;
}

void Update(int a, int b, int c, int k, int l, int r) {
	if (a == l && b == r) {
		tree[k].v += (b - a + 1) * c;
		tree[k].lazy += c; // 注意是 +=
		return;
	}
	PushDown(k);
	int chl = 2 * k + 1;
	int chr = 2 * k + 2;
	int mid = (l + r) / 2;
	if (a > mid) {
		Update(a, b, c, chr, mid + 1, r);
	}
	else if (b <= mid) {
		Update(a, b, c, chl, l, mid);
	}
	else {
		Update(a, mid, c, chl, l, mid);
		Update(mid + 1, b, c, chr, mid + 1, r);
	}
	tree[k].v = tree[chl].v + tree[chr].v;
}

ll Query(int a, int b, int k, int l, int r) {
	if (a == l && b == r) {
		return tree[k].v;
	}
	PushDown(k);
	int chl = 2 * k + 1;
	int chr = 2 * k + 2;
	int mid = (r + l) / 2;
	if (a > mid) {
		return Query(a, b, chr, mid + 1, r);
	}
	else if (b <= mid) {
		return Query(a, b, chl, l, mid);
	}
	else {
		ll v1 = Query(a, mid, chl, l, mid);
		ll v2 = Query(mid + 1, b, chr, mid + 1, r);
		return v1 + v2;
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i ++) scanf("%d", a + i);
	Init(0, 0, N - 1);
	for (int i = 0; i < Q; i ++) {
		char op[2]; int a, b, c;
		scanf("%s", op);
		if (!strcmp(op, "C")) {
			scanf("%d%d%d", &a, &b, &c);
			Update(a - 1, b - 1, c, 0, 0, N - 1);
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%lld\n", Query(a - 1, b - 1, 0, 0, N - 1));
		}
	}
	return 0;
}
