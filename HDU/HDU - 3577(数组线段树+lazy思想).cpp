#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
int data[4 * maxn];
int lazy[4 * maxn];
int ans[100005];
int k, Q;
int T;

void PushDown(int k) {
	int chl = k << 1;
	int chr = k << 1 | 1;
	data[chl] += lazy[k];
	data[chr] += lazy[k];
	lazy[chl] += lazy[k];
	lazy[chr] += lazy[k];
	lazy[k] = 0;
}

void Update(int a, int b, int k, int l, int r) {
	if (a == l && b == r) {
		data[k] += 1;
		lazy[k] += 1;
		return;
	}
	PushDown(k);
	int chl = k << 1;
	int chr = k << 1 | 1;
	int m = (l + r) / 2;
	if (m < a) Update(a, b, chr, m + 1, r);
	else if (m >= b) Update(a, b, chl, l, m);
	else {
		Update(a, m, chl, l, m);
		Update(m + 1, b, chr, m + 1, r);
	}
	data[k] = max(data[chl], data[chr]);
}

int Query(int a, int b, int k, int l, int r) {
	if (a == l && b == r) {
		return data[k];
	}
	PushDown(k);
	int chl = k << 1;
	int chr = k << 1 | 1;
	int m = (l + r) / 2;
	if (m < a) return Query(a, b, chr, m + 1, r);
	else if (m >= b) return Query(a, b, chl, l, m);
	else {
		return max(Query(a, m, chl, l, m), Query(m + 1, b, chr, m + 1, r));
	}
}

int main() {
	scanf("%d", &T);
	int cnt = 1;
	while (T --) {
		int len = 0;
		scanf("%d%d", &k, &Q);
		memset(data, 0, sizeof data);
		memset(lazy, 0, sizeof lazy);
		for (int i = 0; i < Q; i ++) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (Query(a, b - 1, 1, 1, 1000000) < k) {
				ans[len ++] = i + 1;
				Update(a, b - 1, 1, 1, 1000000);
			}
		}
		printf("Case %d:\n", cnt ++);
		for (int i = 0; i < len; i ++) printf("%d ", ans[i]);
		printf("\n\n");
	}
	return 0;
}
